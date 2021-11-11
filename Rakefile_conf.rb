# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#                                                                     #
# The ACME project                                                    #
#                                                                     #
# Copyright (c) 2020-2021, Davide Stocco and Enrico Bertolazzi.       #
#                                                                     #
# The ACME project and its components are supplied under the terms of #
# the open source BSD 2-Clause License. The contents of the ACME      #
# project and its components may not be copied or disclosed except in #
# accordance with the terms of the BSD 2-Clause License.              #
#                                                                     #
# URL: https://opensource.org/licenses/BSD-2-Clause                   #
#                                                                     #
#    Davide Stocco                                                    #
#    Department of Industrial Engineering                             #
#    University of Trento                                             #
#    e-mail: davide.stocco@unitn.it                                   #
#                                                                     #
#    Enrico Bertolazzi                                                #
#    Department of Industrial Engineering                             #
#    University of Trento                                             #
#    e-mail: enrico.bertolazzi@unitn.it                               #
#                                                                     #
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

# Check for a conf file on a upper directory
if File.exists?(File.expand_path('../Rakefile_conf.rb', File.dirname(__FILE__))) then
  require_relative '../Rakefile_conf.rb'
else
  COMPILE_DEBUG      = false
  COMPILE_DYNAMIC    = false
  COMPILE_EXECUTABLE = false
  USE_NMAKE          = true

  case RUBY_PLATFORM
  when /mingw|mswin/
    PARALLEL = ''
    QUIET    = ''
  else
    require 'etc'
    cmakeversion = %x( cmake --version ).scan(/\d+\.\d+\.\d+/).last
    mm = cmakeversion.split('.');
    if mm[0].to_i > 3 || (mm[0].to_i == 3 && mm[1].to_i >= 12) then
      PARALLEL = "--parallel #{Etc.nprocessors} "
      QUIET    = '-- --quiet '
    else
      PARALLEL = ''
      QUIET    = ''
    end
  end
end
