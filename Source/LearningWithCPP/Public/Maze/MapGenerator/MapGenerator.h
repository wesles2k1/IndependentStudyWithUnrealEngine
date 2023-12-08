#pragma once

#include "../Map/Map.h"
#include "../MapParameters/MapOption.h"

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MapGenerator.generated.h"

// Static class that builds a maze based on set MapTypes
UCLASS(BlueprintType, Blueprintable)
class LEARNINGWITHCPP_API UMapGenerator final : public UObject {
    GENERATED_BODY()
    
    public:
        UFUNCTION(BlueprintCallable)
        static void SetMapTypes(TArray<FMapOption> givenMapTypes);
        UFUNCTION(BlueprintCallable, BlueprintPure)
        static TArray<FMapOption> GetMapTypes();

        // Two rooms horizontally connected by a single door
        UFUNCTION(BlueprintCallable)
        static AMap* BuildMazeTwoRooms(UObject* context);
        // Builds a maze by adding rooms to doors that have been randomly added to rooms
        UFUNCTION(BlueprintCallable)
        static AMap* BuildMazeProcedural(UObject* context);
        // Builds a maze with the Binary Tree algorithm
        UFUNCTION(BlueprintCallable)
        static AMap* BuildMazeTree(UObject* context);
        // Builds a maze using Kruskal's algorithm; Makes a rectangularly filled maze
        UFUNCTION(BlueprintCallable)
        static AMap* BuildMazeKruskal(UObject* context);
        
    private:
        // Private deleted constructor to prevent instantiation of this class
        //UMapGenerator() = delete;
        
        // A work around to have a private static non-constant variable with a default value
        // This is treated similarly to a variable, just wrapped within a function
        static TArray<FMapOption>& MapTypes();

        // Map Factory Method
        static AMap* MakeMap(UWorld* world);

        static ARoom* BuildRoom(int id, /*Direction direction, */TArray<FMapOption> mapTypes);

        // Returns a random MapFactory from the list based on corresponding odds
        static MapFactory* RandomFactory(TArray<FMapOption>& mapTypes);

        // Reformats given FMapOptions, removing duplicate factories, impossible odds, and normalizing odds to (0.0, 1.0]
        static void PrepFMapOptions(TArray<FMapOption>& mapTypes);
};