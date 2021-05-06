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
*/

// TEST 0 - ACME MATHEMATICS TESTS

#include <iostream>

#include "acme.hh"
#include "acme_math.hh"
#include "acme_utilities.hh"

int main(void)
{

  std::cout << "TEST 0 - ACME MATHEMATICS TESTS"
            << std::endl
            << std::endl;

  // EPSILON TEST
  acme::real Epsilon_machine = acme::Epsilon_Machine;
  acme::real Epsilon_acme = acme::epsilon();
  std::cout << "Epsilon TEST" << std::endl
            << "Epsilon (machine) = " << Epsilon_machine << std::endl
            << "Epsilon (acme)    = " << Epsilon_acme << std::endl
            << std::endl;

  // INFINITY TEST
  acme::real Infinity_acme = acme::infinity();
  std::cout << "INFINITY TEST" << std::endl
            << "Infinity (acme)   = " << Infinity_acme << std::endl
            << std::endl;

  // SINE TEST
  double value = acme::PI;
  std::cout << "SINE TEST" << std::endl
            << "Sin(PI) = " << acme::sin(value) << std::endl
            << "Cos(PI) = " << acme::cos(value) << std::endl
            << "Tan(PI) = " << acme::tan(value) << std::endl;

  // POW TEST
  std::cout << "POW TEST" << std::endl
            << "Pow(2.0, 2.0) = " << acme::pow(2.0, 2.0) << std::endl
            << std::endl;

  return 0;
}
