
.. _program_listing_file_include_acme_AABBtree.hh:

Program Listing for File acme_AABBtree.hh
=========================================

|exhale_lsh| :ref:`Return to documentation for file <file_include_acme_AABBtree.hh>` (``include/acme_AABBtree.hh``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   /*
   (***********************************************************************)
   (*                                                                     *)
   (* The ACME project                                                    *)
   (*                                                                     *)
   (* Copyright (c) 2020-2021, Davide Stocco and Enrico Bertolazzi.       *)
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
   #include "acme_aabb.hh"
   #include "acme_math.hh"
   
   namespace acme
   {
   
     /*\
      |      _        _    ____  ____  _                 
      |     / \      / \  | __ )| __ )| |_ _ __ ___  ___ 
      |    / _ \    / _ \ |  _ \|  _ \| __| '__/ _ \/ _ \
      |   / ___ \  / ___ \| |_) | |_) | |_| | |  __/  __/
      |  /_/   \_\/_/   \_\____/|____/ \__|_|  \___|\___|
      |                                                  
     \*/
   
   
     class AABBtree
     {
     public:
       typedef std::shared_ptr<AABBtree> ptr; 
       typedef std::vector<ptr> vecptr;       
   
     private:
       aabb::ptr m_ptrbox; 
       AABBtree::vecptr m_children;
   
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
           aabb::vecptr const &boxes 
       );
   
       void
       print(
           out_stream &stream, 
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
   
         // check aabb with
         if (!tree.m_ptrbox->intersects(*this->m_ptrbox))
           return false;
   
         int icase = (this->m_children.empty() ? 0 : 1) +
                     (tree.m_children.empty() ? 0 : 2);
   
         switch (icase)
         {
         case 0: // both leaf, use aabb intersection algorithm
           if (swap_tree)
             return function(tree.m_ptrbox, this->m_ptrbox);
           else
             return function(this->m_ptrbox, tree.m_ptrbox);
         case 1: // first is a tree, second is a leaf
         {
           typename AABBtree::vecptr::const_iterator it;
           for (it = this->m_children.begin(); it != this->m_children.end(); ++it)
             if (tree.collision(**it, function, !swap_tree))
               return true;
         }
         break;
         case 2: // first leaf, second is a tree
         {
           typename AABBtree::vecptr::const_iterator it;
           for (it = tree.m_children.begin();
                it != tree.m_children.end(); ++it)
             if (this->collision(**it, function, swap_tree))
               return true;
         }
         break;
         case 3: // first is a tree, second is a tree
         {
           typename AABBtree::vecptr::const_iterator it1;
           typename AABBtree::vecptr::const_iterator it2;
           for (it1 = this->m_children.begin(); it1 != this->m_children.end(); ++it1)
             for (it2 = tree.m_children.begin();
                  it2 != tree.m_children.end(); ++it2)
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
           aabb::vecpairptr &intersectionList, 
           bool swap_tree = false              
       ) const;
   
     private:
       void selectMinimumDistance(
           point const &query,         
           aabb::vecptr &candidateList 
       ) const;
   
       static real
       minimumExteriorDistance(
           point const &query,   
           AABBtree const &tree, 
           real distance         
       );
   
       static void
       selectLessThanDistance(
           point const &query,         
           real distance,              
           AABBtree const &tree,       
           aabb::vecptr &candidateList 
       );
   
     }; // class AABBtree
   
   } // namespace acme
   
   ///
