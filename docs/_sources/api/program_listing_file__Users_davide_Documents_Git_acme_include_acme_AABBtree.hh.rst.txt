
.. _program_listing_file__Users_davide_Documents_Git_acme_include_acme_AABBtree.hh:

Program Listing for File acme_AABBtree.hh
=========================================

|exhale_lsh| :ref:`Return to documentation for file <file__Users_davide_Documents_Git_acme_include_acme_AABBtree.hh>` (``/Users/davide/Documents/Git/acme/include/acme_AABBtree.hh``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   /*
   (***********************************************************************)
   (*                                                                     *)
   (* The ACME project - Release Version 0.0.0                            *)
   (*                                                                     *)
   (* Copyright (c) 2020 Davide Stocco, All Rights Reserved.              *)
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
   (***********************************************************************)
   (*                                                                     *)
   (*  Reference:                                                         *)
   (*  Efficient intersection between splines of clothoids.               *)
   (*  Enrico Bertolazzi, Paolo Bevilacqua, Marco Frego                   *)
   (*  October 2019 - Mathematics and Computers in Simulation 176         *)
   (*  DOI: 10.1016/j.matcom.2019.10.001                                  *)
   (*                                                                     *)
   (*  URL: https://github.com/ebertolazzi/Clothoids                      *)
   (*                                                                     *)
   (***********************************************************************)
   */
   
   
   #include "acme.hh"
   #include "acme_math.hh"
   #include "acme_box.hh"
   
   namespace acme
   {
   
     /*\
      |      _        _    ____  ____  _
      |     / \      / \  | __ )| __ )| |_ _ __ ___  ___
      |    / _ \    / _ \ |  _ \|  _ \| __| '__/ _ \/ _ \
      |   / ___ \  / ___ \| |_) | |_) | |_| | |  __/  __/
      |  /_/   \_\/_/   \_\____/|____/ \__|_|  \___|\___|
     \*/
   
   
     class AABBtree
     {
     public:
   #ifdef ACME_USE_CXX11
       typedef std::shared_ptr<AABBtree> ptr; 
   #else
       typedef AABBtree *ptr; 
   #endif
   
     private:
       box::ptr ptrbox; 
       std::vector<AABBtree::ptr> children;
   
       AABBtree(AABBtree const &tree);
   
     public:
       ~AABBtree();
   
       AABBtree();
   
       void
       clear(void);
   
       bool
       isEmpty(void) const;
   
       void
       build(
           std::vector<box::ptr> const &boxes 
       );
   
       void
       print(
           ostream_type &stream, 
           int level = 0         
       ) const;
   
       template <typename collision>
       bool
       collision(
           AABBtree const &tree,  
           collision function,    
           bool swap_tree = false 
       ) const
       {
   
         // check box with
         if (!tree.ptrbox->intersects(*ptrbox))
           return false;
   
         int icase = (children.empty() ? 0 : 1) +
                     (tree.children.empty() ? 0 : 2);
   
         switch (icase)
         {
         case 0: // both leaf, use box intersection algorithm
           if (swap_tree)
             return function(tree.ptrbox, ptrbox);
           else
             return function(ptrbox, tree.ptrbox);
         case 1: // first is a tree, second is a leaf
         {
           typename std::vector<AABBtree::ptr>::const_iterator it;
           for (it = children.begin(); it != children.end(); ++it)
             if (tree.collision(**it, function, !swap_tree))
               return true;
         }
         break;
         case 2: // first leaf, second is a tree
         {
           typename std::vector<AABBtree::ptr>::const_iterator it;
           for (it = tree.children.begin();
                it != tree.children.end(); ++it)
             if (this->collision(**it, function, swap_tree))
               return true;
         }
         break;
         case 3: // first is a tree, second is a tree
         {
           typename std::vector<AABBtree::ptr>::const_iterator it1;
           typename std::vector<AABBtree::ptr>::const_iterator it2;
           for (it1 = children.begin(); it1 != children.end(); ++it1)
             for (it2 = tree.children.begin();
                  it2 != tree.children.end(); ++it2)
               if ((*it1)->collision(**it2, function, swap_tree))
                 return true;
         }
         break;
         }
         return false;
       }
   
       void
       intersection(
           AABBtree const &tree,              
           box::vecpairptr &intersectionList, 
           bool swap_tree = false             
       ) const;
   
       void selectMinimumDistance(
           vec3 const &point,         
           box::vecptr &candidateList 
       ) const;
   
     private:
       static real_type
       minimumExteriorDistance(
           vec3 const &point,    
           AABBtree const &tree, 
           real_type distance    
       );
   
       static void
       selectLessThanDistance(
           vec3 const &point,         
           real_type distance,        
           AABBtree const &tree,      
           box::vecptr &candidateList 
       );
   
     }; // class AABBtree
   
   } // namespace acme
   
   ///
