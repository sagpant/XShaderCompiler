/*
 * GLSLKeywords.cpp
 * 
 * This file is part of the XShaderCompiler project (Copyright (c) 2014-2016 by Lukas Hermanns)
 * See "LICENSE.txt" for license information.
 */

#include "GLSLKeywords.h"
#include <set>
#include <map>


namespace Xsc
{


/*
Here are a few references for HLSL-to-GLSL mappings:
https://anteru.net/blog/2016/mapping-between-hlsl-and-glsl/
https://msdn.microsoft.com/en-us/windows/uwp/gaming/glsl-to-hlsl-reference
*/

/* ------ GLSL Keywords ----- */

static std::set<std::string> GenerateKeywordSet()
{
    return
    {
        "main",
        //TODO: add all GLSL keywords ...
    };
}

bool IsGLSLKeyword(const std::string& ident)
{
    static const auto keywordSet = GenerateKeywordSet();
    return (keywordSet.find(ident) != keywordSet.end());
}


/* ----- DataType Mapping ----- */

static std::map<DataType, std::string> GenerateDataTypeMap()
{
    using T = DataType;

    return
    {
        { T::Bool,      "bool"   },
        { T::Int,       "int"    },
        { T::UInt,      "uint"   },
        { T::Half,      "float"  },
        { T::Float,     "float"  },
        { T::Double,    "double" },

        { T::Bool2,     "bvec2"  },
        { T::Bool3,     "bvec3"  },
        { T::Bool4,     "bvec4"  },
        { T::Int2,      "ivec2"  },
        { T::Int3,      "ivec3"  },
        { T::Int4,      "ivec4"  },
        { T::UInt2,     "uvec2"  },
        { T::UInt3,     "uvec3"  },
        { T::UInt4,     "uvec4"  },
        { T::Half2,     "vec2"   },
        { T::Half3,     "vec3"   },
        { T::Half4,     "vec4"   },
        { T::Float2,    "vec2"   },
        { T::Float3,    "vec3"   },
        { T::Float4,    "vec4"   },
        { T::Double2,   "dvec2"  },
        { T::Double3,   "dvec3"  },
        { T::Double4,   "dvec4"  },

        { T::Float2x2,  "mat2"   },
        { T::Float2x3,  "mat2x3" },
        { T::Float2x4,  "mat2x4" },
        { T::Float3x2,  "mat3x2" },
        { T::Float3x3,  "mat3"   },
        { T::Float3x4,  "mat3x4" },
        { T::Float4x2,  "mat4x2" },
        { T::Float4x3,  "mat4x3" },
        { T::Float4x4,  "mat4"   },
        { T::Double2x2, "mat2"   },
        { T::Double2x3, "mat2x3" },
        { T::Double2x4, "mat2x4" },
        { T::Double3x2, "mat3x2" },
        { T::Double3x3, "mat3"   },
        { T::Double3x4, "mat3x4" },
        { T::Double4x2, "mat4x2" },
        { T::Double4x3, "mat4x3" },
        { T::Double4x4, "mat4"   },
    };
}

const std::string* DataTypeToGLSLKeyword(const DataType dataType)
{
    static const auto dataTypeMap = GenerateDataTypeMap();
    auto it = dataTypeMap.find(dataType);
    return (it != dataTypeMap.end() ? &(it->second) : nullptr);
}


/* ----- StorageClass Mapping ----- */

static std::map<StorageClass, std::string> GenerateStorageClassMap()
{
    using T = StorageClass;

    return
    {
        { T::Extern,          "extern"        },
      //{ T::Precise,         ""              },
        { T::Shared,          "shared"        },
        { T::GroupShared,     "shared"        },
        { T::Static,          "static"        },
        { T::Uniform,         "uniform"       },
        { T::Volatile,        "volatile"      },

        { T::NoInterpolation, "flat"          },
        { T::Linear,          "smooth"        },
        { T::Centroid,        "centroid"      },
        { T::NoPerspective,   "noperspective" },
        { T::Sample,          "sample"        },
    };
}

const std::string* StorageClassToGLSLKeyword(const StorageClass storageClass)
{
    static const auto storageClassMap = GenerateStorageClassMap();
    auto it = storageClassMap.find(storageClass);
    return (it != storageClassMap.end() ? &(it->second) : nullptr);
}


} // /namespace Xsc



// ================================================================================