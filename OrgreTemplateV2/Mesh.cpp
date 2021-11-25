#include "Mesh.h"

/// Creats and returns a manual object to be used as the cube mesh
/// 
///
/// <param name="name"> Name id for the manual object</param>
/// <param name="matName"> The name of the material to be used</param>
/// <returns> Returns the cube shaped manual object</returns>
Ogre::ManualObject* MyMesh::createCubeMesh(Ogre::String name, Ogre::String matName, Ogre::Vector3 clr)
{
    Ogre::ManualObject* cube = new Ogre::ManualObject(name);
    cube->begin(matName);

    cube->position(0.5, -0.5, 1.0); cube->colour(clr.x, clr.y, clr.z); cube->textureCoord(1, 0);   //0
    cube->position(-0.5, -0.5, 0.0); cube->colour(clr.x, clr.y, clr.z); cube->textureCoord(0, 1);  //1
    cube->position(0.5, -0.5, 0.0); cube->colour(clr.x, clr.y, clr.z); cube->textureCoord(1, 1);    //2
    cube->position(-0.5, -0.5, 1.0); cube->colour(clr.x, clr.y, clr.z); cube->textureCoord(0, 0);   //3
    cube->position(0.5, 0.5, 1.0); cube->colour(clr.x, clr.y, clr.z); cube->textureCoord(1, 0);       //4
    cube->position(-0.5, -0.5, 1.0); cube->colour(clr.x, clr.y, clr.z); cube->textureCoord(0, 1);   //5 
    cube->position(0.5, -0.5, 1.0); cube->colour(clr.x, clr.y, clr.z); cube->textureCoord(1, 1);     //6
    cube->position(-0.5, 0.5, 1.0); cube->colour(clr.x, clr.y, clr.z); cube->textureCoord(0, 0);     //7
    cube->position(-0.5, 0.5, 0.0); cube->colour(clr.x, clr.y, clr.z); cube->textureCoord(0, 1);    //8
    cube->position(-0.5, -0.5, 0.0); cube->colour(clr.x, clr.y, clr.z); cube->textureCoord(1, 1);  //9
    cube->position(-0.5, -0.5, 1.0); cube->colour(clr.x, clr.y, clr.z); cube->textureCoord(1, 0);    //10
    cube->position(0.5, -0.5, 0.0); cube->colour(clr.x, clr.y, clr.z); cube->textureCoord(0, 1);    //11
    cube->position(0.5, 0.5, 0.0); cube->colour(clr.x, clr.y, clr.z); cube->textureCoord(1, 1);      //12
    cube->position(0.5, -0.5, 1.0); cube->colour(clr.x, clr.y, clr.z); cube->textureCoord(0, 0);    //13
    cube->position(0.5, -0.5, 0.0); cube->colour(clr.x, clr.y, clr.z); cube->textureCoord(1, 0);   //14
    cube->position(-0.5, -0.5, 0.0); cube->colour(clr.x, clr.y, clr.z); cube->textureCoord(0, 0);   //15
    //TOP
    cube->position(-0.5, 0.5, 1.0); cube->colour(clr.x, clr.y, clr.z); cube->textureCoord(1, 0);     //16
    cube->position(0.5, 0.5, 0.0); cube->colour(clr.x, clr.y, clr.z); cube->textureCoord(0, 1);    //17
    cube->position(-0.5, 0.5, 0.0); cube->colour(clr.x, clr.y, clr.z); cube->textureCoord(1, 1);   //18
    cube->position(0.5, 0.5, 1.0); cube->colour(clr.x, clr.y, clr.z); cube->textureCoord(0, 0);      //19

    cube->triangle(0, 1, 2);		cube->triangle(3, 1, 0);
    cube->triangle(4, 5, 6);		cube->triangle(4, 7, 5);
    cube->triangle(8, 9, 10);		cube->triangle(10, 7, 8);
    cube->triangle(4, 11, 12);	cube->triangle(4, 13, 11);
    cube->triangle(14, 8, 12);	cube->triangle(14, 15, 8);
    cube->triangle(16, 17, 18);	cube->triangle(16, 19, 17);
    cube->end();
   
    //cube->setBoundingBox(Ogre::AxisAlignedBox::BOX_INFINITE);
    return cube;
}
/// Creats and returns a manual object to be used as the sphere mesh
/// 
/// 
/// <param name="name">Name id for the manual object</param>
/// <param name="matName">The name of the material to be used</param>
/// <param name="r"> radius of the sphere</param>
/// <returns>Returns the sphere shaped manual object</returns>
Ogre::ManualObject* MyMesh::createSphereMesh(Ogre::String name, Ogre::String matName, const float r, Ogre::Vector3 clr)
{
    const int nRings = 16;
    const int nSegments = 16;

    Ogre::ManualObject* sphere = new Ogre::ManualObject(name);
    sphere->begin(matName);

    float fDeltaRingAngle = (Ogre::Math::PI / nRings);
    float fDeltaSegAngle = (2 * Ogre::Math::PI / nSegments);
    unsigned short wVerticeIndex = 0;

    // Generate the group of rings for the sphere
    for (int ring = 0; ring <= nRings; ring++) {
        float r0 = r * sinf(ring * fDeltaRingAngle);
        float y0 = r * cosf(ring * fDeltaRingAngle);

        // Generate the group of segments for the current ring
        for (int seg = 0; seg <= nSegments; seg++) {
            float x0 = r0 * sinf(seg * fDeltaSegAngle);
            float z0 = r0 * cosf(seg * fDeltaSegAngle);

            // Add one vertex to the strip which makes up the sphere
            sphere->position(x0, y0, z0);
            sphere->colour(clr.x,clr.y,clr.z);
            sphere->normal(Ogre::Vector3(x0, y0, z0).normalisedCopy());
            sphere->textureCoord((float)seg / (float)nSegments, (float)ring / (float)nRings);

            if (ring != nRings) {
                // each vertex (except the last) has six indicies pointing to it
                sphere->index(wVerticeIndex + nSegments + 1);
                sphere->index(wVerticeIndex);
                sphere->index(wVerticeIndex + nSegments);
                sphere->index(wVerticeIndex + nSegments + 1);
                sphere->index(wVerticeIndex + 1);
                sphere->index(wVerticeIndex);
                wVerticeIndex++;
            }
        }; // end for seg
    } // end for ring
    sphere->end();

    return sphere;
}
