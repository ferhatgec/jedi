// MIT License
//
// Copyright (c) 2021 Ferhat Geçdoğan All Rights Reserved.
// Distributed under the terms of the MIT License.
//
//

#include <fstream>
#include <memory>
#include "../include/jedi.hpp"
#include "../include/jedi_helpers.hpp"

Jedi::Jedi(std::string const filename) {
    std::ifstream data(filename);

    for(std::string temporary; std::getline(data, temporary);
        this->file_data.append(temporary + "\n"))
        ;
}

std::string Jedi::get(std::string argument) noexcept {
    auto data = split(argument, ':');
    Kedi init; init.ReadStr(this->file_data);

    return this->extract(std::get<1>(init.Tree->Extract(data.at(0), data.at(1))));
}

std::string Jedi::extract(std::string data) noexcept {
    std::string extracted_data;

    for(auto& character : data) {
        if(character == '\'') { continue; }

        extracted_data.push_back(character);
    }

    return extracted_data;
}

int main(int argc, char** argv) noexcept {
    if(argc < 2) {
        std::cout << "Jedi - CLI Kedi parser\n"; std::exit(1);
    }

    std::unique_ptr<Jedi> init(new Jedi(std::string(argv[1])));

    for(auto i = 2; i < argc; i++) {
        std::cout << "\033[0;97m" << init->get(std::string(argv[i])) << "\033[0m\n";
    }
}