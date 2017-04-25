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

#ifndef VHDL_AST_ENUMERATIONLITDECL_H
#define VHDL_AST_ENUMERATIONLITDECL_H

#include "vhdl_analysis_identifier.h"
#include "vhdl_ast_abstractnode.h"
#include "vhdl_ast_enumerationtypedecl.h"
#include "vhdl_ast_isoverloadabletrait.h"

#include <cstdint>

namespace YaVHDL::Analyser::AST
{

class EnumerationTypeDecl;

class EnumerationLitDecl : public AbstractNode, public IsOverloadableTrait {
public:
    ~EnumerationLitDecl();
    void debug_print();

    Identifier *id;
    char c;

    bool is_char_lit;

    uint64_t idx;
    // Non-owning reference to the enumeration type declaration that created
    // this particular literal.
    EnumerationTypeDecl *corresponding_type_decl;
};

}

#endif
