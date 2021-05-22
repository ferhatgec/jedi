// MIT License
//
// Copyright (c) 2021 Ferhat Geçdoğan All Rights Reserved.
// Distributed under the terms of the MIT License.
//
//

#ifndef JEDI_JEDI_HPP
#define JEDI_JEDI_HPP

#include <iostream>
#include <string>

#include "../lib/kedi/include/kedi_main.hpp"

class Jedi {
    std::string file_data;
public:
    Jedi (std::string const filename);
    ~Jedi()= default;

    std::string get(std::string argument) noexcept;
    std::string extract(std::string data) noexcept;
};

#endif // JEDI_JEDI_HPP