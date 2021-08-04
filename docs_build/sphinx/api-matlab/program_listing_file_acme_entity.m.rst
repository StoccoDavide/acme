
.. _program_listing_file_acme_entity.m:

Program Listing for File acme_entity.m
======================================

|exhale_lsh| :ref:`Return to documentation for file <file_acme_entity.m>` (``acme_entity.m``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: MATLAB

   % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
   %                                                                     %
   % The ACME project                                                    %
   %                                                                     %
   % Copyright (c) 2020-2021, Davide Stocco and Enrico Bertolazzi.       %
   %                                                                     %
   % The ACME project and its components are supplied under the terms of %
   % the open source BSD 2-Clause License. The contents of the ACME      %
   % project and its components may not be copied or disclosed except in %
   % accordance with the terms of the BSD 2-Clause License.              %
   %                                                                     %
   % URL: https://opensource.org/licenses/BSD-2-Clause                   %
   %                                                                     %
   %    Davide Stocco                                                    %
   %    Department of Industrial Engineering                             %
   %    University of Trento                                             %
   %    e-mail: davide.stocco@unitn.it                                   %
   %                                                                     %
   %    Enrico Bertolazzi                                                %
   %    Department of Industrial Engineering                             %
   %    University of Trento                                             %
   %    e-mail: enrico.bertolazzi@unitn.it                               %
   %                                                                     %
   % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
   
   classdef acme_entity < handle
     %>
     %> Class container for ACME entity object
     %>
     properties (SetAccess = protected, Hidden = true)
       objectHandle; %> Handle to the underlying C++ class instance
     end
     %
     % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
     %
     %> Create a new entity object instance
     methods
       function self = acme_entity( )
       end
     end
     %
     % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
     %
     %> Get object type as string (virtual method)
     methods (Abstract)
       type( self )
     end
   end
