#include "AWall.h"

AWall::AWall() {

}

AMapSite* AWall::Enter() {
    GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, TEXT("Ran into wall!"));

    return this;
}