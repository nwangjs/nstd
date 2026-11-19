#pragma once

#include <nstd/type_traits.hpp>

namespace nstd {

template <typename T>
constexpr remove_reference_t<T>&& move(T&& value) noexcept {
    return static_cast<remove_reference_t<T>&&>(value);
}

}  // namespace nstd
