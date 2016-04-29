#ifndef COMPONENTTYPE
#define COMPONENTTYPE

namespace MagEngine
{

/***
 *
 * ComponentType
 *
 * The enum defines ID for component types
 *
 */
enum ComponentType
{
    // Renderer section
    RENDERER,

    // Nav mesh section
    NAVMESHAGENT,

    // Lighting section
    LIGHT,
    POINTLIGHT,
    DIRECTIONALLIGHT,

    // Camera section
    CAMERA
};

}

#endif // COMPONENTTYPE

