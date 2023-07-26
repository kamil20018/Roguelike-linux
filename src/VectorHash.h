#pragma once
#include <SFML/Graphics.hpp>

namespace std {
    template <class T>
    struct hash<sf::Vector2<T>> {
        std::size_t operator()(const sf::Vector2<T>& v) const {
            using std::hash;

            // Compute individual hash values for first
            // and second. Combine them using the Boost-func

            std::size_t tmp0 = hash<T>()(v.x);
            std::size_t tmp1 = hash<T>()(v.y);

            tmp0 ^= tmp1 + 0x9e3779b9 + (tmp0 << 6) + (tmp0 >> 2);
            return tmp0;
        }
    };
}