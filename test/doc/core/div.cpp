// revision 1
#include <eve/module/core.hpp>
#include <iostream>

int main()
{
  using wf_t = eve::wide<float, eve::fixed<4>>;
  wf_t pf = {3, 2, 3, 32700}, qf = {4, 1, 1, 100};

  std::cout << "---- simd" << '\n'
            << " <- pf                    = " << pf << '\n'
            << " <- qf                    = " << qf << '\n'
            << " -> div(pf, qf)           = " << eve::div(pf, qf) << '\n'
            << " -> pf / qf               = " << pf / qf << '\n'
            << " -> div[pf> qf](pf, qf)    = " << eve::div[pf>qf](pf, qf) << '\n';


  wf_t rf = {3034, 200, 333, 32700}, sf = {4, 7, 13, 100};

  std::cout << "---- simd" << '\n'
            << " <- rf                       = " << rf << '\n'
            << " <- sf                       = " << sf << '\n'
            << " -> toward_zero(div)(rf, sf) = " << eve::div[eve::toward_zero](rf, sf) << '\n'
            << " -> downward(div)(rf, sf)    = " << eve::div[eve::downward](rf, sf)    << '\n'
            << " -> upward(div)(rf, sf)      = " << eve::div[eve::upward](rf, sf)      << '\n'
            << " -> to_nearest(div)(rf, sf)  = " << eve::div[eve::to_nearest](rf, sf)  << '\n';

  auto k = kumi::tuple{pf, pf, pf, 1};
  std::cout << "---- multi parameters" << '\n'
            << " -> div(k)                        = " << eve::div(k)                       << '\n'
            << " -> div(kumi::tuple{pf, pf})      = " << eve::div( kumi::tuple{pf, pf})    << '\n'
            << " -> div(kumi::tuple{pf, 1.0f)     = " << eve::div( kumi::tuple{pf, 1.0f})  << '\n'
            << " -> div(kumi::tuple{1.0f, pf)     = " << eve::div( kumi::tuple{1.0f, pf})  << '\n';
}
