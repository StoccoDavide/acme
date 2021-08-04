
.. _program_listing_file_include_acme_intersection.hh:

Program Listing for File acme_intersection.hh
=============================================

|exhale_lsh| :ref:`Return to documentation for file <file_include_acme_intersection.hh>` (``include/acme_intersection.hh``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   /*
   (***********************************************************************)
   (*                                                                     *)
   (* The ACME project                                                    *)
   (*                                                                     *)
   (* Copyright (c) 2020-2021_in, Davide Stocco and Enrico Bertolazzi.       *)
   (*                                                                     *)
   (* The ACME project and its components are supplied under the terms of *)
   (* the open source BSD 2-Clause License. The contents of the ACME      *)
   (* project and its components may not be copied or disclosed except in *)
   (* accordance with the terms of the BSD 2-Clause License.              *)
   (*                                                                     *)
   (* URL: https://opensource.org/licenses/BSD-2-Clause                   *)
   (*                                                                     *)
   (*    Davide Stocco                                                    *)
   (*    Department of Industrial Engineering                             *)
   (*    University of Trento                                             *)
   (*    e-mail: davide.stocco@unitn.it                                   *)
   (*                                                                     *)
   (*    Enrico Bertolazzi                                                *)
   (*    Department of Industrial Engineering                             *)
   (*    University of Trento                                             *)
   (*    e-mail: enrico.bertolazzi@unitn.it                               *)
   (*                                                                     *)
   (***********************************************************************)
   */
   
   
   #ifndef INCLUDE_ACME_INTERSECTION
   #define INCLUDE_ACME_INTERSECTION
   
   #include "acme.hh"
   #include "acme_aabb.hh"
   #include "acme_collinear.hh"
   #include "acme_coplanar.hh"
   #include "acme_disk.hh"
   #include "acme_line.hh"
   #include "acme_none.hh"
   #include "acme_plane.hh"
   #include "acme_ray.hh"
   #include "acme_segment.hh"
   #include "acme_ball.hh"
   #include "acme_triangle.hh"
   
   namespace acme
   {
   
     /*\
      |   ___       _                          _   _
      |  |_ _|_ __ | |_ ___ _ __ ___  ___  ___| |_(_) ___  _ __
      |   | || '_ \| __/ _ \ '__/ __|/ _ \/ __| __| |/ _ \| '_ \
      |   | || | | | ||  __/ |  \__ \  __/ (__| |_| | (_) | | | |
      |  |___|_| |_|\__\___|_|  |___/\___|\___|\__|_|\___/|_| |_|
      |
     \*/
   
     entity *
     intersection(
         entity const *entity0_in, 
         entity const *entity1_in, 
         real tolerance = EPSILON  
     );
   
     /*\
      |   ____                   _               _ 
      |  |  _ \ _   _ _ __   ___| |_ _   _  __ _| |
      |  | |_) | | | | '_ \ / __| __| | | |/ _` | |
      |  |  __/| |_| | | | | (__| |_| |_| | (_| | |
      |  |_|    \__,_|_| |_|\___|\__|\__,_|\__,_|_| 
      |                                            
     \*/
   
     bool
     intersection(
         point const &point0_in,             
         point const &point1_in,             
         point &point_out = THROWAWAY_POINT, 
         real tolerance = EPSILON            
     );
   
     bool
     intersection(
         point const &point_in,              
         line const &line_in,                
         point &point_out = THROWAWAY_POINT, 
         real tolerance = EPSILON            
     );
   
     bool
     intersection(
         point const &point_in,              
         ray const &ray_in,                  
         point &point_out = THROWAWAY_POINT, 
         real tolerance = EPSILON            
     );
   
     bool
     intersection(
         point const &point_in,              
         plane const &plane_in,              
         point &point_out = THROWAWAY_POINT, 
         real tolerance = EPSILON            
     );
   
     bool
     intersection(
         point const &point_in,              
         segment const &segment_in,          
         point &point_out = THROWAWAY_POINT, 
         real tolerance = EPSILON            
     );
   
     bool
     intersection(
         point const &point_in,              
         triangle const &triangle_in,        
         point &point_out = THROWAWAY_POINT, 
         real tolerance = EPSILON            
     );
   
     bool
     intersection(
         point const &point_in,              
         disk const &disk_in,                
         point &point_out = THROWAWAY_POINT, 
         real tolerance = EPSILON            
     );
   
     /*\
      |    ____      _ _ _
      |   / ___|___ | | (_)_ __   ___  __ _ _ __
      |  | |   / _ \| | | | '_ \ / _ \/ _` | '__|
      |  | |__| (_) | | | | | | |  __/ (_| | |
      |   \____\___/|_|_|_|_| |_|\___|\__,_|_|
      |
     \*/
   
     bool
     intersection(
         line const &line0_in,            
         line const &line1_in,            
         line &line_out = THROWAWAY_LINE, 
         real tolerance = EPSILON         
     );
   
     bool
     intersection(
         ray const &ray0_in,           
         ray const &ray1_in,           
         ray &ray_out = THROWAWAY_RAY, 
         real tolerance = EPSILON      
     );
   
     bool
     intersection(
         ray const &ray0_in,                       
         ray const &ray1_in,                       
         segment &segment_out = THROWAWAY_SEGMENT, 
         real tolerance = EPSILON                  
     );
   
     bool
     intersection(
         segment const &segment0_in,               
         segment const &segment1_in,               
         segment &segment_out = THROWAWAY_SEGMENT, 
         real tolerance = EPSILON                  
     );
   
     bool
     intersection(
         line const &line_in,          
         ray const &ray_in,            
         ray &ray_out = THROWAWAY_RAY, 
         real tolerance = EPSILON      
     );
   
     bool
     intersection(
         line const &line_in,                      
         segment const &segment_in,                
         segment &segment_out = THROWAWAY_SEGMENT, 
         real tolerance = EPSILON                  
     );
   
     bool
     intersection(
         ray const &ray_in,                        
         segment const &segment_in,                
         segment &segment_out = THROWAWAY_SEGMENT, 
         real tolerance = EPSILON                  
     );
   
     /*\
      |    ____                      _
      |   / ___| ___ _ __   ___ _ __(_) ___
      |  | |  _ / _ \ '_ \ / _ \ '__| |/ __|
      |  | |_| |  __/ | | |  __/ |  | | (__
      |   \____|\___|_| |_|\___|_|  |_|\___|
      |
     \*/
   
     bool
     intersection(
         line const &line0_in,               
         line const &line1_in,               
         point &point_out = THROWAWAY_POINT, 
         real tolerance = EPSILON            
     );
   
     bool
     intersection(
         ray const &ray0_in,                 
         ray const &ray1_in,                 
         point &point_out = THROWAWAY_POINT, 
         real tolerance = EPSILON            
     );
   
     bool
     intersection(
         segment const &segment0_in,         
         segment const &segment1_in,         
         point &point_out = THROWAWAY_POINT, 
         real tolerance = EPSILON            
     );
   
     bool
     intersection(
         line const &line_in,                
         ray const &ray_in,                  
         point &point_out = THROWAWAY_POINT, 
         real tolerance = EPSILON            
     );
   
     bool
     intersection(
         line const &line_in,                
         segment const &segment,             
         point &point_out = THROWAWAY_POINT, 
         real tolerance = EPSILON            
     );
   
     bool
     intersection(
         ray const &ray_in,                  
         segment const &segment,             
         point &point_out = THROWAWAY_POINT, 
         real tolerance = EPSILON            
     );
   
     /*\
      |    ____            _
      |   / ___|___  _ __ | | __ _ _ __   __ _ _ __
      |  | |   / _ \| '_ \| |/ _` | '_ \ / _` | '__|
      |  | |__| (_) | |_) | | (_| | | | | (_| | |
      |   \____\___/| .__/|_|\__,_|_| |_|\__,_|_|
      |             |_|
     \*/
   
     bool
     intersection(
         plane const &plane0_in,        
         plane const &plane1_in,        
         plane &plane_out = plane_goat, 
         real tolerance = EPSILON       
     );
   
     bool
     intersection(
         triangle const &triangle0_in,    
         triangle const &triangle1_in,    
         none &none_out = THROWAWAY_NONE, 
         real tolerance = EPSILON         
     );
   
     bool
     intersection(
         disk const &disk0_in,            
         disk const &disk1_in,            
         none &none_out = THROWAWAY_NONE, 
         real tolerance = EPSILON         
     );
   
     bool
     intersection(
         line const &line_in,             
         plane const &plane_in,           
         line &line_out = THROWAWAY_LINE, 
         real tolerance = EPSILON         
     );
   
     bool
     intersection(
         line const &line_in,                      
         triangle const &triangle_in,              
         segment &segment_out = THROWAWAY_SEGMENT, 
         real tolerance = EPSILON                  
     );
   
     bool
     intersection(
         line const &line_in,                      
         disk const &disk_in,                      
         segment &segment_out = THROWAWAY_SEGMENT, 
         real tolerance = EPSILON                  
     );
   
     bool
     intersection(
         ray const &ray_in,            
         plane const &plane_in,        
         ray &ray_out = THROWAWAY_RAY, 
         real tolerance = EPSILON      
     );
   
     bool
     intersection(
         ray const &ray_in,                        
         triangle const &triangle_in,              
         segment &segment_out = THROWAWAY_SEGMENT, 
         real tolerance = EPSILON                  
     );
   
     bool
     intersection(
         ray const &ray_in,                        
         disk const &disk_in,                      
         segment &segment_out = THROWAWAY_SEGMENT, 
         real tolerance = EPSILON                  
     );
   
     bool
     intersection(
         plane const &plane_in,                    
         segment const &segment_in,                
         segment &segment_out = THROWAWAY_SEGMENT, 
         real tolerance = EPSILON                  
     );
   
     bool
     intersection(
         plane const &plane_in,                       
         triangle const &triangle_in,                 
         triangle &triangle_out = THROWAWAY_TRIANGLE, 
         real tolerance = EPSILON                     
     );
   
     bool
     intersection(
         plane const &plane_in,           
         disk const &disk_in,             
         disk &disk_out = THROWAWAY_DISK, 
         real tolerance = EPSILON         
     );
   
     bool
     intersection(
         segment const &segment_in,                
         triangle const &triangle_in,              
         segment &segment_out = THROWAWAY_SEGMENT, 
         real tolerance = EPSILON                  
     );
   
     bool
     intersection(
         segment const &segment_in,                
         disk const &disk_in,                      
         segment &segment_out = THROWAWAY_SEGMENT, 
         real tolerance = EPSILON                  
     );
   
     bool
     intersection(
         triangle const &triangle_in,     
         disk const &disk_in,             
         none &none_out = THROWAWAY_NONE, 
         real tolerance = EPSILON         
     );
   
     /*\
      |   _   _              ____            _
      |  | \ | | ___  _ __  / ___|___  _ __ | | __ _ _ __   __ _ _ __
      |  |  \| |/ _ \| '_ \| |   / _ \| '_ \| |/ _` | '_ \ / _` | '__|
      |  | |\  | (_) | | | | |__| (_) | |_) | | (_| | | | | (_| | |
      |  |_| \_|\___/|_| |_|\____\___/| .__/|_|\__,_|_| |_|\__,_|_|
      |                               |_|
     \*/
   
     bool
     intersection(
         plane const &plane0_in,          
         plane const &plane1_in,          
         line &line_out = THROWAWAY_LINE, 
         real tolerance = EPSILON         
     );
   
     bool
     intersection(
         plane const &plane0_in,             
         plane const &plane1_in,             
         plane const &plane2_in,             
         point &point_out = THROWAWAY_POINT, 
         real tolerance = EPSILON            
     );
   
     bool
     intersection(
         triangle const &triangle0_in,             
         triangle const &triangle1_in,             
         segment &segment_out = THROWAWAY_SEGMENT, 
         real tolerance = EPSILON                  
     );
   
     bool
     intersection(
         disk const &disk0_in,                     
         disk const &disk1_in,                     
         segment &segment_out = THROWAWAY_SEGMENT, 
         real tolerance = EPSILON                  
     );
   
     bool
     intersection(
         ball const &ball0_in,        
         ball const &ball1_in,        
         none &none_out = THROWAWAY_NONE, 
         real tolerance = EPSILON         
     );
   
     bool
     intersection(
         line const &line_in,                
         plane const &plane_in,              
         point &point_out = THROWAWAY_POINT, 
         real tolerance = EPSILON            
     );
   
     bool
     intersection(
         line const &line_in,                
         triangle const &triangle_in,        
         point &point_out = THROWAWAY_POINT, 
         real tolerance = EPSILON            
     );
   
     bool
     intersection(
         line const &line_in,                
         disk const &disk_in,                
         point &point_out = THROWAWAY_POINT, 
         real tolerance = EPSILON            
     );
   
     bool
     intersection(
         line const &line_in,                      
         ball const &ball_in,                  
         segment &segment_out = THROWAWAY_SEGMENT, 
         real tolerance = EPSILON                  
     );
   
     bool
     intersection(
         ray const &ray_in,                  
         plane const &plane_in,              
         point &point_out = THROWAWAY_POINT, 
         real tolerance = EPSILON            
     );
   
     bool
     intersection(
         ray const &ray_in,                  
         triangle const &triangle_in,        
         point &point_out = THROWAWAY_POINT, 
         real tolerance = EPSILON            
     );
   
     bool
     intersection(
         ray const &ray_in,                  
         disk const &disk_in,                
         point &point_out = THROWAWAY_POINT, 
         real tolerance = EPSILON            
     );
   
     bool
     intersection(
         ray const &ray_in,                        
         ball const &ball_in,                  
         segment &segment_out = THROWAWAY_SEGMENT, 
         real tolerance = EPSILON                  
     );
   
     bool
     intersection(
         plane const &plane_in,              
         segment const &segment,             
         point &point_out = THROWAWAY_POINT, 
         real tolerance = EPSILON            
     );
   
     bool
     intersection(
         plane const &plane_in,                    
         triangle const &triangle_in,              
         segment &segment_out = THROWAWAY_SEGMENT, 
         real tolerance = EPSILON                  
     );
   
     bool
     intersection(
         plane const &plane_in,                    
         disk const &disk_in,                      
         segment &segment_out = THROWAWAY_SEGMENT, 
         real tolerance = EPSILON                  
     );
   
     bool
     intersection(
         plane const &plane_in,           
         ball const &ball_in,         
         disk &disk_out = THROWAWAY_DISK, 
         real tolerance = EPSILON         
     );
   
     bool
     intersection(
         segment const &segment_in,          
         triangle const &triangle_in,        
         point &point_out = THROWAWAY_POINT, 
         real tolerance = EPSILON            
     );
   
     bool
     intersection(
         segment const &segment_in,          
         disk const &disk_in,                
         point &point_out = THROWAWAY_POINT, 
         real tolerance = EPSILON            
     );
   
     bool
     intersection(
         segment const &segment_in,                
         ball const &ball_in,                  
         segment &segment_out = THROWAWAY_SEGMENT, 
         real tolerance = EPSILON                  
     );
   
     bool
     intersection(
         triangle const &triangle_in,              
         disk const &disk_in,                      
         segment &segment_out = THROWAWAY_SEGMENT, 
         real tolerance = EPSILON                  
     );
   
     bool
     intersection(
         triangle const &triangle_in,     
         ball const &ball_in,         
         none &none_out = THROWAWAY_NONE, 
         real tolerance = EPSILON         
     );
   
     bool
     intersection(
         disk const &disk_in,             
         ball const &ball_in,         
         none &none_out = THROWAWAY_NONE, 
         real tolerance = EPSILON         
     );
   
     /*\
      |   __  __ _              _ _
      |  |  \/  (_)___  ___ ___| | | __ _ _ __   ___  ___  _   _ ___
      |  | |\/| | / __|/ __/ _ \ | |/ _` | '_ \ / _ \/ _ \| | | / __|
      |  | |  | | \__ \ (_|  __/ | | (_| | | | |  __/ (_) | |_| \__ \
      |  |_|  |_|_|___/\___\___|_|_|\__,_|_| |_|\___|\___/ \__,_|___/
      |
     \*/
   
     bool
     intersection(
         aabb const &aabb0_in,            
         aabb const &aabb1_in,            
         aabb &aabb_out = THROWAWAY_AABB, 
         real tolerance = EPSILON         
     );
   
   } // namespace acme
   
   #endif
   
   ///
