/*
(***********************************************************************)
(*                                                                     *)
(* The ACME project                                                    *)
(*                                                                     *)
(* Copyright (c) 2020, Davide Stocco and Enrico Bertolazzi.            *)
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

// TEST 0 - ACME MATHEMATICS TESTS

#include <iostream>

#include "acme.hh"
#include "acme_math.hh"
#include "acme_utils.hh"

int main(void)
{

  std::cout << "TEST 0 - ACME MATHEMATICS TESTS"
            << std::endl
            << std::endl;

  // EPSILON TEST
  std::cout << "Epsilon TEST" << std::endl
            << "Epsilon (machine) = " << acme::EPSILON_MACHINE << std::endl
            << "Epsilon (acme)    = " << acme::EPSILON << std::endl
            << std::endl;

  // INFINITY TEST
  std::cout << "INFINITY TEST" << std::endl
            << "Infinity (acme)   = " << acme::INFTY << std::endl
            << std::endl;

  // NOT-A-NUMBER TEST
  std::cout << "QUIET NOT-A-NUMBER TEST" << std::endl
            << "Quiet NaN (acme)   = " << acme::QUIET_NAN << std::endl
            << std::endl;

  return 0;
}
