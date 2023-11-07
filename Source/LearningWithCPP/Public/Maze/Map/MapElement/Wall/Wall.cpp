#include "Wall.h"

Wall::Wall() {

}

MapSite* Wall::Enter() {
    GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, TEXT("Ran into wall!"));

    return this;
}