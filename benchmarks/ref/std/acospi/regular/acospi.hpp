//==================================================================================================
/**
  EVE - Expressive Vector Engine
  Copyright 2020 Joel FALCOU
  Copyright 2020 Jean-Thierry LAPRESTE

  Licensed under the MIT License <http://opensource.org/licenses/MIT>.
  SPDX-License-Identifier: MIT
**/
//==================================================================================================
#include <cmath>
#include <numbers>

int main(int argc, char** argv)
{
  constexpr EVE_TYPE invpi = std::numbers::inv_pi_v<EVE_TYPE>;
  auto const std_acospi = [invpi](auto x) { return invpi*std::acos(x); };

  EVE_REGISTER_BENCHMARK(std_acospi, EVE_TYPE, eve::bench::random<EVE_TYPE>(-1.,1.));

  eve::bench::start_benchmarks(argc, argv);
}