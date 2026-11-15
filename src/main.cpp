#include <iostream>
#include <limits>

    int option;
    int noOfReadings = 0;
   
    struct sensorReadings {
        int temperature;
        int humidity;
    };

     sensorReadings reading[10];
     int readingSize = sizeof(reading)/sizeof(reading[0]);
   

 void option1 () {

    int readingsToEnter;
    int remainingSlots = readingSize - noOfReadings;

    if (noOfReadings == readingSize) {
        std::cout << "Maximum number of readings reached. \n";
        return;
    }

    while (true) {
        std::cout << "How many readings do you want to enter? \n";
        std::cin >> readingsToEnter;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid number \n";
        }else if (readingsToEnter < 1) {
            std::cout << "Please enter at least 1 reading \n";
        }else if ( readingsToEnter > remainingSlots) {
            std::cout << "Insufficient storage space. Please enter a smaller number.\n";
        }else {
            break;
        }

    }
    int endIndex = noOfReadings + readingsToEnter;

        for (int i = noOfReadings; i < endIndex ; i++) {
        std::cout << "Enter temperature reading (-10°C - 60 °C) for Reading #" << i+1 << ": \n";
        while(true) {
             std::cin >> reading[i].temperature;

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << " Invalid input. Please enter a number. \n";
            }else if (reading[i].temperature <-10 || reading[i].temperature > 60) {
                std::cout << "Temperature must be between -10°C and 60°C. \n";
            }else {
                break;
            }
        }

        std::cout << "Enter humidity reading (0% - 100%) for Reading #" << i+1 << ": \n";
        while(true) {
            std::cin >> reading[i].humidity;

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << " Invalid input. Please enter a number. \n";
            }else if (reading[i].humidity < 0 || reading[i].humidity > 100) {
                std::cout << "Humidity must be between 0% and 100% \n";
            }else {
                break;
            }
 
        }
        noOfReadings++;
    }
        std::cout << "Sensor readings saved successfully! \n";
}

void option2 () {
    if (noOfReadings > 0) {
        std::cout << "\n============= STORED SENSOR READINGS ============= \n";

    for (int i =0; i < noOfReadings; i++) {
        std::cout << "-------Reading " << i+1 << "-----------\n";
        std::cout << "Temperature: " << reading[i].temperature << " °C \n";
        std::cout << "Humidity: " << reading[i].humidity << "% \n";
    }
    std::cout << "================================================== \n";
} else {
    std::cout << "No readings available. Please enter readings first. \n";
}
}

void option3 () {

    if (noOfReadings > 0) {
        int sumT = 0;
        int sumH = 0;
        for (int i = 0; i < noOfReadings; i++) {
            sumT += reading[i].temperature;
            sumH += reading[i].humidity;
        }

        double averageTemperature = static_cast <double> (sumT) / noOfReadings;
        double averageHumidity = static_cast <double> (sumH) / noOfReadings;

        std::cout << "\n============ AVERAGE SENSOR READINGS ===========\n";
        std::cout << "Average temperature: " << averageTemperature << " °C \n";
        std::cout << "Average Humidity: " << averageHumidity << " % \n";
        std::cout << "=====================================================\n";

    } else {
        std::cout << "No readings available. Please enter readings first. \n";
    }
}

void option4 () {
    if (noOfReadings > 0) {
        int highest = reading[0].temperature;
        for (int i = 1; i < noOfReadings; i++) {
        if (reading[i].temperature > highest) {
            highest = reading[i].temperature;
        }
    }
    std::cout << "\n============ HIGHEST TEMPERATURE READING ===========\n";
    std::cout << "The highest temperature is: " << highest << " °C \n";
    std::cout << "=====================================================\n";
    } else {
        std::cout << "No readings available. Please enter readings first. \n";
    }
}

void option5 () {
    if (noOfReadings > 0) {
        std::cout << "\n============ ENVIRONMENTAL CONDITIONS ===========\n";

        for (int i = 0; i < noOfReadings; i++) {
        std::cout << "\n-----Reading " << i+1 << " ------------\n";
        std::cout << "Temperature: " << reading[i].temperature << " °C \n";
        if (reading[i].temperature < 20) {
            std::cout << "Status: Low temperature \n";
        } else if (reading[i].temperature <= 30) {
            std::cout <<  "Status: Normal temperature \n";
        } else {
            std::cout << "Status: High temperature \n";
        }

        std::cout << "Humidity: " << reading[i].humidity << " % \n";
        if (reading[i].humidity < 30) {
            std::cout << "Status: Low humidity \n";
        } else if (reading[i].humidity <= 70) {
            std::cout <<  " Status: Normal humidity \n";
        } else {
            std::cout << "Status: High humidity \n";
        }
    }
    std::cout << "\n===========================================\n";

        } else {
        std::cout << "No readings available. Please enter reading first \n";
    }
}

int main () {

    do {
        std::cout << "\n=================================\n";
        std::cout << "   GREENHOUSE MONITORING SYSTEM \n";
        std::cout << "================================\n";
        std::cout << "1. Enter sensor readings \n";
        std::cout << "2. View all readings \n";
        std::cout << "3. Calculate average readings \n";
        std::cout << "4. Find highest temperature \n";
        std::cout << "5. Check environmental conditions \n";
        std::cout << "6. EXIT \n";
        std::cout << "_____________________________________\n";
        std::cout << " CHOOSE AN OPTION FROM 1-6 \n";
        

         while(true) {
            std::cin >> option;

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << " Invalid input, enter a number \n";
            }else if (option < 1 || option > 6) {
                std::cout << "enter values between 1 - 6 \n";
            }else {
                break;
            }
        }

        switch (option) {
            case 1: option1 ();
            break;
            case 2: option2 ();
            break;
            case 3: option3 ();
            break;
            case 4: option4 ();
            break;
            case 5: option5 ();
            break;
            case 6: std::cout << " -------- BYE ---------\n";
            break;
            default: std::cout << "invalid option, please choose between 1-6 \n";
        }
    } while (option !=6);
}
