/*
Copyright (c) 2016-2017, Robert Ou <rqou@robertou.com>
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice,
   this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "vhdl_analysis_design_db.h"

#include <iostream>
#include "util.h"
using namespace YaVHDL::Analyser;

Library::~Library() {
    delete this->id;
    
    for (auto i = this->db_by_order.begin();
         i != this->db_by_order.end(); i++) {

        delete (*i);
    }
}

void Library::debug_print() {
    std::cout << "{\"type\": \"Library\"";

    std::cout << ", \"id\": ";
    this->id->debug_print();

    std::cout << ", \"units\": [";

    bool first = true;
    for (auto i = this->db_by_order.begin();
         i != this->db_by_order.end(); i++) {

        if (!first) {
            std::cout << ", ";
        }
        first = false;

        (*i)->debug_print();
    }

    std::cout << "]}";
}

void Library::AddDesignUnit(Identifier name, AST::AbstractNode *unit) {
    this->db_by_name.insert({{name, unit}});
    this->db_by_order.push_back(unit);
}

AST::AbstractNode *Library::FindDesignUnit(Identifier name) {
    auto unit = this->db_by_name.find(name);
    if (unit == this->db_by_name.end())
        return NULL;
    return unit->second;
}
