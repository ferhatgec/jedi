// MIT License
//
// Copyright (c) 2021 Ferhat Geçdoğan All Rights Reserved.
// Distributed under the terms of the MIT License.
//
//

#ifndef JEDI_JEDI_HELPERS_HPP
#define JEDI_JEDI_HELPERS_HPP

#include <vector>
#include <sstream>
#include "jedi.hpp"

namespace {
    std::vector<std::string> split(std::string& data, char delimiter) noexcept {
        std::istringstream stream(data);
        std::vector<std::string> splitted_string;

        for(std::string temporary; std::getline(stream, temporary, delimiter);
            splitted_string.push_back(temporary))
            ;

        return splitted_string;
    }
}

#endif // JEDI_JEDI_HELPERS_HPP
