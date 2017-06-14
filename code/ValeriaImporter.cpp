/*
Open Asset Import Library (assimp)
----------------------------------------------------------------------

Copyright (c) 2006-2017, assimp team

All rights reserved.

Redistribution and use of this software in source and binary forms,
with or without modification, are permitted provided that the
following conditions are met:

* Redistributions of source code must retain the above
  copyright notice, this list of conditions and the
  following disclaimer.

* Redistributions in binary form must reproduce the above
  copyright notice, this list of conditions and the
  following disclaimer in the documentation and/or other
  materials provided with the distribution.

* Neither the name of the assimp team, nor the names of its
  contributors may be used to endorse or promote products
  derived from this software without specific prior
  written permission of the assimp team.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------
*/
#include "ValeriaImporter.h"

namespace Assimp {
namespace Valeria {

static const std::string Extension = "val";

static const aiImporterDesc desc = {
    "Valentina File Format",
    "",
    "",
    "",
    aiImporterFlags_SupportTextFlavour,
    0,
    0,
    0,
    0,
    Extension.c_str()
};

ValeriaImporter::ValeriaImporter() 
: BaseImporter() {
	// empty
}

ValeriaImporter::~ValeriaImporter() {
	// empty
}

bool ValeriaImporter::CanRead( const std::string &file, IOSystem* pIOHandler, bool checkSig ) const {
    if ( !checkSig ) {
        return SimpleExtensionCheck( file, Extension.c_str() );
    } else {
        static const char *tokens[] = { "<pattern>", "<version>", "<author>", "<unit>", "<patternName>", "<patternNumber>" };
        return BaseImporter::SearchFileHeaderForToken( pIOHandler, file, tokens, 6 );
    }

    return false;
}

const aiImporterDesc* ValeriaImporter::GetInfo() const {
    return &desc;
}
    
void ValeriaImporter::InternReadFile( const std::string& pFile, aiScene* pScene, IOSystem* pIOHandler ) {
    int i = 0;
    i++;
}

} // Namespace Valeria
} // Namespace Assimp