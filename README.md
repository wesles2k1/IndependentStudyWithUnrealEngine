# Independent Study With Unreal Engine - Progress
This is a repository to hold an Unreal Engine project with the purpose of developing C++ skills within Unreal Engine, as well as to use them to learn more about design patterns. This project is for-credit in the form of an Independent Study at PennWest Edinboro University.

This project will be divided into three portions: first, to get acquainted with the usage of C++ within Unreal Engine, then to learn more about design patterns that may be useful in game design with C++, and lastly, to combine the first two portions together to implement design patterns into an Unreal Engine project with C++.

## Table of Contents
- [Part 1 - C++ in Unreal Engine](#part1)
  - [Week 1 - Setup, C++ Basics, and Temperature Converter](#week1)
    - [8/29/2023 - Created GitHub repository and added Unreal Project](#8/29/2023)
    - [9/1/2023 - Level and Interaction System](#9/1/2023)
    - [9/2/2023 - Built Temperature Converter UI](#9/2/2023)
    - [9/3/2023 - Built and Implemented Temperature Converter C++ Object](#9/3/2023)
  - [Week 2 - Documentation, Enumerations, and an Animal Selector](#week2)
    - [9/5/2023 - New Parameters and Documentation](#9/5/2023)

<a name="part1"></a>
## Part 1 - C++ in Unreal Engine

<a name="week1"></a>
### Week 1 - Setup, C++ Basics, and Temperature Converter

  For the first week of this project, a main goal was set to have a simple temperature converter working that involves calculations within a C++ object that communicates back and forth with a higher-level Blueprint. This goal serves as a way to introduce the Blueprint/C++ communication process and methods.

<a name="8/29/2023"></a>
#### 8/29/2023 - Created GitHub repository and added Unreal Project!

  To begin the project, an Unreal Engine project was created and used to create this GitHub repository. This was done primarily by following a tutorial by [Matt Aspland](https://www.youtube.com/watch?v=n3x1fErlmYA&t=6s) tutorial. Unreal Engine 5.2 is being used, and this part of the project is built upon the default Third Person template.
  
  ![GitHubSetup](https://github.com/wesles2k1/IndependentStudyWithUnrealEngine/assets/98764304/f8ca9508-3b5b-4c89-ad7d-20c1f579c98e)

  Once the repository was set up, a basic version of this README was filled out, a test push was made with a minimal change in the project, and a few other small things were done to ensure the project is ready to be added to.
  
  ![GitHubInitialPushes](https://github.com/wesles2k1/IndependentStudyWithUnrealEngine/assets/98764304/3126d37c-38ed-4dda-ba44-dc4f66110df9)

<a name="9/1/2023"></a>
#### 9/1/2023 - Level and Interaction System

  As a first move, the default ThirdPersonMap was duplicated and adjusted to better fit the needs of this project. As the first goal is to create a temperature converter, it seemed appropriate to make a simple interaction system that may be reused for future weeks' goals. A BPInteractableBase Blueprint was made to support later uses, and a BPTemperatureConverter was derived for the focus of this week. It's job is simply to be a tangible object in the world that can be interacted with to provide the user with a prompt to input data.
  
  Additionally, two tutorials were followed along to get acquainted with basic use of C++ in Unreal Engine in preparation for the temperature converter (tutorials by [Gorka Games](https://www.youtube.com/watch?v=HNfpKFER2hI) and [Ryan Laley](https://www.youtube.com/watch?v=FBpnOuCgHu4)). Comments within the Blueprints created for each tutorial go into further detail, but their uses are no longer required for the project other than to reference later.

<a name="9/2/2023"></a>
#### 9/2/2023 - Built Temperature Converter UI

  The last step before stepping into C++ was to create an interface through which the user may input data, a temperature they wish to have converted. This UI, named TemperatureWidget, was build with the future C++ object implementation in mind and was made a separate object from the BPTemperatureConverter. It consists of a back button to exit, a button to calculate the conversion, and two text boxes for the user to type in: one for a temperature numerical value and the other for a unit, either Fahrenheit or Celcius, the value is given as.
  
  ![TemperatureWidget](https://github.com/wesles2k1/IndependentStudyWithUnrealEngine/assets/98764304/b93115c3-a9f9-4ff6-9d6d-926fbecaab05)


<a name="9/3/2023"></a>
#### 9/3/2023 - Built and Implemented Temperature Converter C++ Object

  This day saw the creation and success of a temperature conversion using a C++ class called `UCTemperatureCalculator`. This class consists of a singular Calculate function, whose purpose is to take in a temperature numerical value and a unit to calculate the other unit's value. The following is the TemperatureWidget Blueprint:
  
  ![BPTemperatureWidget](https://github.com/wesles2k1/IndependentStudyWithUnrealEngine/assets/98764304/7497e97e-bd05-4c29-8551-f13d96e5f89c)
  
  The bulk of the nodes make up the Blueprint-end behavior, such as opening and closing the UI, (although it is also where the `UCTemperatureCalculator` is instantiated,) while the smaller portion on the bottom is where the `UCTemperatureCalculator`'s `Calculate` function is called:
  
  ![CTemperatureCalculator_CalculateBP](https://github.com/wesles2k1/IndependentStudyWithUnrealEngine/assets/98764304/96feb8c2-66a8-4e10-8a71-ffaf5b7ced9d)

  The `text` from the input textboxes could be converted to strings, but it felt appropriate to attempt working with this new datatype, known as `FText`, and use it as the parameters and return value to keep as much work in the C++ portion as possible. All it really meant, though, was just converting them to `FStrings` (Unreal Engine's equivalent to the usual `std::string`) and working with them from there.
  
  In addition to the actual conversion, messages were generated to be returned in the case of unexpected or wrong input for clarity. The following are pictures of the function within the implementation and header files, respectively:
  
  ![CTemperatureCalculatorCPP](https://github.com/wesles2k1/IndependentStudyWithUnrealEngine/assets/98764304/2904105a-a79c-4e13-8ad2-d8662aa563ca)
  
  ![CTemperatureCalculatorH](https://github.com/wesles2k1/IndependentStudyWithUnrealEngine/assets/98764304/ad79bbea-a82e-4bfd-ac8e-c7bb915d5441)

  Here, a demonstration of it functioning can be seen:

  https://github.com/wesles2k1/IndependentStudyWithUnrealEngine/assets/98764304/8bda65e3-a630-44fe-ab83-88591a86d855

  Note: Small changes were made between the recording of this video and the screenshots of `CTemperatureCalculator`, hence the appearance of "C" and "F" in the output messages.

<a name="week2"></a>
### Week 2 - Documentation, Enumerations, and an Animal Selector

  For the second week, the main goal is to make an interface that lists a selection of animals that the user may select from to receive an output through the use of a slightly more complicated C++ class and an enumerator as both a parameter and return type. Additional goals for this week include experimenting with additional data types (`int`, `float`, and `FString`) as parameters and return types, reworking this README file for more clear documentation, and looking into a better C++ file structure.

<a name="9/5/2023"></a>
#### 9/5/2023 - New Parameters and Documentation

  To begin the week, the secondary goal of extra data types as parameters and return values was explored. To do so, the temperature calculator was revisited and the `Calculate` function was duplicated for adjustment. This new function took in parameters of a `float` and an `FString` while the return value was made into a `float` instead of `FText`s (the `FText` casts were just done in the Blueprint). While this proved to work fine and showed that these data types may be used normally, the function was named `CalculateBad` since it couldn't account for unexpected/wrong input as well as before. The following are its implementation and declaration:
  
  ![CTemperatureCalculator_CalculateBadCPP](https://github.com/wesles2k1/IndependentStudyWithUnrealEngine/assets/98764304/bef8cc2b-2eaa-4417-bc9d-3461fff1fdcd)
  
  ![CTemperatureCalculator_CalculateBadH](https://github.com/wesles2k1/IndependentStudyWithUnrealEngine/assets/98764304/e054e19d-1f2c-4a8f-a389-4969f6b78f61)

  The Blueprint interaction:
  
  ![CTemperatureCalculator_CalculateBadBP](https://github.com/wesles2k1/IndependentStudyWithUnrealEngine/assets/98764304/dbdfdb1c-59f5-4b23-a176-d562f5db6716)

  The results:
  
  ![CalculateBadResultsFloat](https://github.com/wesles2k1/IndependentStudyWithUnrealEngine/assets/98764304/4c342781-9d62-4d3f-83bc-26ff3c7c7f42)

  After this experiment, one more step was taken to consider `int`. The `CalculateBad` function was altered again to return an `int` that was simply a cast from the previous `float` value (further emphasizing the "Bad" of the function's name):
  
  ![CTemperatureCalculator_CalculateBadIntReturn](https://github.com/wesles2k1/IndependentStudyWithUnrealEngine/assets/98764304/56df9cea-51ed-4686-85ec-930b048ae53a)

  The altered Blueprint:
  
  ![CTemperatureCalculator_CalculateBadBPInt](https://github.com/wesles2k1/IndependentStudyWithUnrealEngine/assets/98764304/28204b4a-9ea8-4b2d-b691-9cbd8305a43f)

  The (Bad) results:
  
  ![CalculateBadResultsInt](https://github.com/wesles2k1/IndependentStudyWithUnrealEngine/assets/98764304/225e3d4b-627f-4b95-90e9-bce340c46ad0)
