/* =========================================================================================

   This is an auto-generated file: Any edits you make may be overwritten!

*/

#pragma once

namespace BinaryData
{
    extern const char*   amd_f;
    const int            amd_fSize = 52625;

    extern const char*   amdbar_f;
    const int            amdbar_fSize = 52282;

    extern const char*   libsuitesparseconfig_a;
    const int            libsuitesparseconfig_aSize = 4368;

    extern const char*   SuiteSparse_config_mk;
    const int            SuiteSparse_config_mkSize = 27780;

    extern const char*   SuiteSparse_config_o;
    const int            SuiteSparse_config_oSize = 3824;

    extern const char*   font_otf;
    const int            font_otfSize = 127428;

    extern const char*   image_png;
    const int            image_pngSize = 3246;

    extern const char*   logo_png;
    const int            logo_pngSize = 1170;

    extern const char*   clickedswitch_png;
    const int            clickedswitch_pngSize = 1707;

    extern const char*   offswitch_png;
    const int            offswitch_pngSize = 775;

    extern const char*   font_ttf;
    const int            font_ttfSize = 47340;

    extern const char*   onswitch_png;
    const int            onswitch_pngSize = 1359;

    // Number of elements in the namedResourceList and originalFileNames arrays.
    const int namedResourceListSize = 12;

    // Points to the start of a list of resource names.
    extern const char* namedResourceList[];

    // Points to the start of a list of resource filenames.
    extern const char* originalFilenames[];

    // If you provide the name of one of the binary resource variables above, this function will
    // return the corresponding data and its size (or a null pointer if the name isn't found).
    const char* getNamedResource (const char* resourceNameUTF8, int& dataSizeInBytes);

    // If you provide the name of one of the binary resource variables above, this function will
    // return the corresponding original, non-mangled filename (or a null pointer if the name isn't found).
    const char* getNamedResourceOriginalFilename (const char* resourceNameUTF8);
}
