//==================================================================================================
/*
  EVE - Expressive Vector Engine
  Copyright : EVE Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#pragma once

#include <eve/concept/compatible.hpp>
#include <eve/concept/value.hpp>
#include <eve/detail/abi.hpp>
#include <eve/detail/category.hpp>
#include <eve/detail/function/bit_cast.hpp>

#include <concepts>
#include <cstddef>

namespace eve::detail
{
  //================================================================================================
  // <<=
  //================================================================================================
  template<integral_scalar_value T, typename N, integral_scalar_value U>
  EVE_FORCEINLINE decltype(auto) self_shl(wide<T,N>& v, wide<U,N> s) noexcept
      requires arm_abi<abi_t<T, N>>
  {
    using i_t = typename wide<T,N>::template rebind <as_integer_t<T, signed>,N>;
    auto const si   = bit_cast(s,as<i_t>()).storage();

    constexpr auto c = categorize<wide<T, N>>();

          if constexpr( c == category::int64x1  ) v = vshl_s64(v, si);
    else  if constexpr( c == category::int32x2  ) v = vshl_s32(v, si);
    else  if constexpr( c == category::int16x4  ) v = vshl_s16(v, si);
    else  if constexpr( c == category::int8x8   ) v = vshl_s8 (v, si);
    else  if constexpr( c == category::uint64x1 ) v = vshl_u64(v, si);
    else  if constexpr( c == category::uint32x2 ) v = vshl_u32(v, si);
    else  if constexpr( c == category::uint16x4 ) v = vshl_u16(v, si);
    else  if constexpr( c == category::uint8x8  ) v = vshl_u8 (v, si);
    else  if constexpr( c == category::int64x2  ) v = vshlq_s64(v, si);
    else  if constexpr( c == category::int32x4  ) v = vshlq_s32(v, si);
    else  if constexpr( c == category::int16x8  ) v = vshlq_s16(v, si);
    else  if constexpr( c == category::int8x16  ) v = vshlq_s8 (v, si);
    else  if constexpr( c == category::uint64x2 ) v = vshlq_u64(v, si);
    else  if constexpr( c == category::uint32x4 ) v = vshlq_u32(v, si);
    else  if constexpr( c == category::uint16x8 ) v = vshlq_u16(v, si);
    else  if constexpr( c == category::uint8x16 ) v = vshlq_u8 (v, si);

    return v;
  }

  template<integral_scalar_value T, typename N, integral_scalar_value U>
  EVE_FORCEINLINE decltype(auto) self_shl(wide<T,N>& v, U s) noexcept
      requires arm_abi<abi_t<T, N>>
  {
    using i_t = typename wide<T,N>::template rebind <as_integer_t<T, signed>,N>;
    v <<= i_t(s);
    return v;
  }

  template<integral_scalar_value T, typename N, std::ptrdiff_t S>
  EVE_FORCEINLINE decltype(auto) self_shl(wide<T,N>& v, index_t<S> const&) noexcept
  requires arm_abi<abi_t<T, N>>
  {
    constexpr auto c = categorize<wide<T, N>>();

    if constexpr(S != 0)
    {
            if constexpr( c == category::int64x1  ) v = vshl_n_s64 (v, S);
      else  if constexpr( c == category::int32x2  ) v = vshl_n_s32 (v, S);
      else  if constexpr( c == category::int16x4  ) v = vshl_n_s16 (v, S);
      else  if constexpr( c == category::int8x8   ) v = vshl_n_s8  (v, S);
      else  if constexpr( c == category::uint64x1 ) v = vshl_n_u64 (v, S);
      else  if constexpr( c == category::uint32x2 ) v = vshl_n_u32 (v, S);
      else  if constexpr( c == category::uint16x4 ) v = vshl_n_u16 (v, S);
      else  if constexpr( c == category::uint8x8  ) v = vshl_n_u8  (v, S);
      else  if constexpr( c == category::int64x2  ) v = vshlq_n_s64(v, S);
      else  if constexpr( c == category::int32x4  ) v = vshlq_n_s32(v, S);
      else  if constexpr( c == category::int16x8  ) v = vshlq_n_s16(v, S);
      else  if constexpr( c == category::int8x16  ) v = vshlq_n_s8 (v, S);
      else  if constexpr( c == category::uint64x2 ) v = vshlq_n_u64(v, S);
      else  if constexpr( c == category::uint32x4 ) v = vshlq_n_u32(v, S);
      else  if constexpr( c == category::uint16x8 ) v = vshlq_n_u16(v, S);
      else  if constexpr( c == category::uint8x16 ) v = vshlq_n_u8 (v, S);
    }

    return v;
  }

  //================================================================================================
  // >>=
  //================================================================================================
  template<integral_scalar_value T, typename N, integral_scalar_value U>
  EVE_FORCEINLINE decltype(auto) self_shr(wide<T,N>& v, wide<U,N> s) noexcept
      requires arm_abi<abi_t<T, N>>
  {
    return self_shl(v, -s);
  }

  template<integral_scalar_value T, typename N, integral_scalar_value U>
  EVE_FORCEINLINE decltype(auto) self_shr(wide<T,N>& v, U s) noexcept
      requires arm_abi<abi_t<T, N>>
  {
    return self_shl(v, -s);
  }

  template<integral_scalar_value T, typename N, std::ptrdiff_t S>
  EVE_FORCEINLINE decltype(auto) self_shr(wide<T,N>& v, index_t<S> const&) noexcept
  requires arm_abi<abi_t<T, N>>
  {
    constexpr auto c = categorize<wide<T, N>>();

    if constexpr(S != 0)
    {
      if       constexpr( c == category::int64x1  ) v = vshr_n_s64 (v, S);
      else  if constexpr( c == category::int32x2  ) v = vshr_n_s32 (v, S);
      else  if constexpr( c == category::int16x4  ) v = vshr_n_s16 (v, S);
      else  if constexpr( c == category::int8x8   ) v = vshr_n_s8  (v, S);
      else  if constexpr( c == category::uint64x1 ) v = vshr_n_u64 (v, S);
      else  if constexpr( c == category::uint32x2 ) v = vshr_n_u32 (v, S);
      else  if constexpr( c == category::uint16x4 ) v = vshr_n_u16 (v, S);
      else  if constexpr( c == category::uint8x8  ) v = vshr_n_u8  (v, S);
      else  if constexpr( c == category::int64x2  ) v = vshrq_n_s64(v, S);
      else  if constexpr( c == category::int32x4  ) v = vshrq_n_s32(v, S);
      else  if constexpr( c == category::int16x8  ) v = vshrq_n_s16(v, S);
      else  if constexpr( c == category::int8x16  ) v = vshrq_n_s8 (v, S);
      else  if constexpr( c == category::uint64x2 ) v = vshrq_n_u64(v, S);
      else  if constexpr( c == category::uint32x4 ) v = vshrq_n_u32(v, S);
      else  if constexpr( c == category::uint16x8 ) v = vshrq_n_u16(v, S);
      else  if constexpr( c == category::uint8x16 ) v = vshrq_n_u8 (v, S);
    }

    return v;
  }

  //================================================================================================
  // |=
  //================================================================================================
  template<scalar_value T, value U, typename N>
  EVE_FORCEINLINE bit_value_t<wide<T, N>, U>& self_bitor(wide<T, N> &self, U const &other) noexcept
      requires((sizeof(wide<T, N>) == sizeof(U)) || (sizeof(T) == sizeof(U))) && arm_abi<abi_t<T, N>>
  {
    using type = wide<T, N>;

    if constexpr( simd_value<U> && sizeof(self) == sizeof(other) )
    {
      auto bit_other = eve::bit_cast(other, as<type> {});
      constexpr auto c = categorize<type>();

            if constexpr( c == category::int64x1  ) self = vorr_s64 (self, bit_other);
      else  if constexpr( c == category::int32x2  ) self = vorr_s32 (self, bit_other);
      else  if constexpr( c == category::int16x4  ) self = vorr_s16 (self, bit_other);
      else  if constexpr( c == category::int8x8   ) self = vorr_s8  (self, bit_other);
      else  if constexpr( c == category::uint64x1 ) self = vorr_u64 (self, bit_other);
      else  if constexpr( c == category::uint32x2 ) self = vorr_u32 (self, bit_other);
      else  if constexpr( c == category::uint16x4 ) self = vorr_u16 (self, bit_other);
      else  if constexpr( c == category::uint8x8  ) self = vorr_u8  (self, bit_other);
      else  if constexpr( c == category::int64x2  ) self = vorrq_s64(self, bit_other);
      else  if constexpr( c == category::int32x4  ) self = vorrq_s32(self, bit_other);
      else  if constexpr( c == category::int16x8  ) self = vorrq_s16(self, bit_other);
      else  if constexpr( c == category::int8x16  ) self = vorrq_s8 (self, bit_other);
      else  if constexpr( c == category::uint64x2 ) self = vorrq_u64(self, bit_other);
      else  if constexpr( c == category::uint32x4 ) self = vorrq_u32(self, bit_other);
      else  if constexpr( c == category::uint16x8 ) self = vorrq_u16(self, bit_other);
      else  if constexpr( c == category::uint8x16 ) self = vorrq_u8 (self, bit_other);
      else  if constexpr( c == category::float32x2)
      {
        self = vreinterpret_f32_u32 ( vorr_u32( vreinterpret_u32_f32(self)
                                              , vreinterpret_u32_f32(bit_other)
                                              )
                                    );
      }
      else  if constexpr( c == category::float32x4)
      {
        self = vreinterpretq_f32_u32( vorrq_u32 ( vreinterpretq_u32_f32(self)
                                                , vreinterpretq_u32_f32(bit_other)
                                                )
                                    );
      }
      else if constexpr( current_api >= asimd)
      {
        if constexpr( c == category::float64x1)
        {
          self = vreinterpret_f64_u64 ( vorr_u64( vreinterpret_u64_f64(self)
                                                , vreinterpret_u64_f64(bit_other)
                                                )
                                      );
        }
        else  if constexpr( c == category::float64x2)
        {
          self = vreinterpretq_f64_u64( vorrq_u64 ( vreinterpretq_u64_f64(self)
                                                  , vreinterpretq_u64_f64(bit_other)
                                                  )
                                      );
        }
      }
    }
    else
    {
      auto bit_other = eve::bit_cast(other, as<T> {});
      self           = self_bitor(self, type {bit_other});
    }

    return self;
  }
}
