%w(colorize rake fileutils).each do |gem|
  begin
    require gem
  rescue LoadError
    warn "Install the #{gem} gem:\n $ (sudo) gem install #{gem}".magenta
    exit 1
  end
end

require_relative "./Rakefile_common.rb"

file_base = File.expand_path(File.dirname(__FILE__)).to_s

cmd_cmake_build = ""
if COMPILE_EXECUTABLE then
  cmd_cmake_build += ' -DBUILD_EXECUTABLE:VAR=true '
else
  cmd_cmake_build += ' -DBUILD_EXECUTABLE:VAR=false '
end
if COMPILE_DYNAMIC then
  cmd_cmake_build += ' -DBUILD_SHARED:VAR=true '
else
  cmd_cmake_build += ' -DBUILD_SHARED:VAR=false '
end
if COMPILE_DEBUG then
  cmd_cmake_build += ' -DCMAKE_BUILD_TYPE:VAR=Debug --loglevel=WARNING '
else
  cmd_cmake_build += ' -DCMAKE_BUILD_TYPE:VAR=Release --loglevel=WARNING '
end
cmd_cmake_build += " -DINSTALL_HERE:VAR=true "

task :default => [:build]

TESTS = [
]

desc "run tests on linux/osx"
task :run do
  TESTS.each do |cmd|
    sh "./bin/#{cmd}"
  end
end

desc "run tests (Release) on windows"
task :run_win do
  TESTS.each do |cmd|
    sh "bin\\Release\\#{cmd}.exe"
  end
end

desc "run tests (Debug) on windows"
task :run_win_debug do
  TESTS.each do |cmd|
    sh "bin\\Debug\\#{cmd}.exe"
  end
end

desc "build lib"
task :build do
  sh "make config"
  sh "make --jobs=8 install_local"
end

def ChangeOnFile( file, text_to_replace, text_to_put_in_place )
  text = File.read file
  File.open(file, 'w+') do |f|
    f << text.gsub(text_to_replace, text_to_put_in_place)
  end
end

desc "compile for Visual Studio [default year=2017, bits=x64]"
task :build_win, [:year, :bits] do |t, args|

  args.with_defaults( :year => "2017", :bits => "x64" )

  dir = "vs_#{args.year}_#{args.bits}"

  FileUtils.rm_rf   dir
  FileUtils.mkdir_p dir
  FileUtils.cd      dir

  FileUtils.mkdir_p "../lib/lib"
  FileUtils.mkdir_p "../lib/bin"
  FileUtils.mkdir_p "../lib/bin/"+args.bits
  FileUtils.mkdir_p "../lib/dll"
  FileUtils.mkdir_p "../lib/include"

  cmd_cmake = win_vs(args.bits,args.year) + cmd_cmake_build

  puts "run CMAKE for UTILS".yellow
  sh cmd_cmake + ' ..'
  puts "compile with CMAKE for UTILS".yellow
  if COMPILE_DEBUG then
    sh 'cmake --build . --config Debug --target install '+PARALLEL+QUIET
  else
    sh 'cmake  --build . --config Release  --target install '+PARALLEL+QUIET
  end

  FileUtils.cd '..'
end

desc 'compile for OSX'
task :build_osx do |t, args|

  dir = "build"

  FileUtils.rm_rf   dir
  FileUtils.mkdir_p dir
  FileUtils.cd      dir

  cmd_cmake = "cmake " + cmd_cmake_build

  puts "run CMAKE for UTILS".yellow
  sh cmd_cmake + ' ..'
  puts "compile with CMAKE for UTILS".yellow
  if COMPILE_DEBUG then
    sh 'cmake --build . --config Debug --target install '+PARALLEL+QUIET
  else
    sh 'cmake --build . --config Release --target install '+PARALLEL+QUIET
  end
  FileUtils.cd '..'
end

desc 'compile for LINUX'
task :build_linux do |t, args|

  dir = "build"

  FileUtils.rm_rf   dir
  FileUtils.mkdir_p dir
  FileUtils.cd      dir

  cmd_cmake = "cmake " + cmd_cmake_build

  puts "run CMAKE for UTILS".yellow
  sh cmd_cmake + ' ..'
  puts "compile with CMAKE for UTILS".yellow
  if COMPILE_DEBUG then
    sh 'cmake --build . --config Debug --target install '+PARALLEL+QUIET
  else
    sh 'cmake --build . --config Release --target install '+PARALLEL+QUIET
  end

  FileUtils.cd '..'
end

desc "clean for OSX"
task :clean_osx do
  FileUtils.rm_rf 'lib'
  sh "make clean"
end

desc "clean for LINUX"
task :clean_linux do
  FileUtils.rm_rf 'lib'
  sh "make clean"
end

desc "clean for WINDOWS"
task :clean_win do
  FileUtils.rm_rf 'lib'
  FileUtils.rm_rf 'vs_*'
end
