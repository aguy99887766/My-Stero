#include <iostream>
#include <string>
#include <sstream>
#include <limits>
class SteroReceiver {
    /*Written by AI, too much stuff to type out*/
    std::string manufacturer;
    std::string model;
    std::string serialNumber;
    int wattage;
    int numChannels;
    std::string band;  
    float frequency;   
    int volume;        
    bool power;       
    int bass;         
    int signal; 

    public:

        SteroReceiver(): manufacturer("Generic"), model("Generic"), serialNumber("Generic"), wattage(40), numChannels(50), band("AM"), frequency(5.43), volume(70), power(false), bass(50), signal(80) {};

        std::string getModel() const { return model; }
        std::string getSerialNumber() const { return serialNumber; }
        int getWattage() const { return wattage; }
        int getNumChannels() const { return numChannels; }
        std::string getBand() const { return band; }
        float getFrequency() const { return frequency; }
        int getVolume() const { return volume; }
        bool getPower() const { return power; }
        int getBass() const { return bass; }
        int getSignal() const { return signal; }

        void setManufacturer(const std::string& m) { manufacturer = m; }
        void setModel(const std::string& m) { model = m; }
        void setSerialNumber(const std::string& sn) { serialNumber = sn; }
        void setWattage(int w) { wattage = w; }
        void setNumChannels(int n) { numChannels = n; }
        void setBand(const std::string& b) { band = b; }
        void setFrequency(float f) { frequency = f; }
        void setVolume(int v) { volume = v; }
        void setPower(bool p) { power = p; }
        void setBass(int b) { bass = b; }
        void setSignal(int s) { signal = s; }

        void display_info() {

            std::cout << "Manufacturer: " << manufacturer << std::endl;
            std::cout << "Model: " << model << std::endl;
            std::cout << "Serial Number: " << serialNumber << std::endl;
            std::cout << "Wattage: " << wattage << "W" << std::endl;
            std::cout << "Number of Channels: " << numChannels << std::endl;
            std::cout << "Band: " << band << std::endl;
            std::cout << "Frequency: " << frequency << " MHz" << std::endl;
            std::cout << "Volume: " << volume << std::endl;
            std::cout << "Power: " << (power ? "On" : "Off") << std::endl;
            std::cout << "Bass: " << bass << std::endl;
            std::cout << "Signal Strength: " << signal << std::endl;
        }
        bool validCheck() {

            try {

                if (wattage > 10 || wattage <= 0) {
                    throw std::string("Wattage cannot exceed 10 or be less than 0");
                }

                if (frequency > 120) {
                    throw std::string("Freqency cannot exceed 120");
                }

                if (signal > 100 || signal <= 0) {
                    throw std::string("The signal strength cannot exceed 100 or be less than 0");
                }

                if (volume > 10 || volume <= 0) {
                    throw std::string("Volume cannot exceed 10 or be less than 0");
                }

                if (model.empty()) {
                    throw std::string("Model cannot be empty");
                }
                if (serialNumber.empty()) {
                    throw std::string("Serial number cannot be empty");
                }
                if (numChannels <= 0) {
                    throw std::string("Number of channels must be greater than 0");
                }


            } catch (const std::string& e) {
                std::cout << e << std::endl;
                return false;
            }

            return true;

        }
};

template <typename T>
void input(const std::string& question, T& value) {
    while (true) {
        std::cout << question << ": ";
        std::cin >> value; 

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Validation failed. Try again." << std::endl;
            
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
        

    }
}


SteroReceiver* stero = new SteroReceiver(); 
void setStero() {
    /*
    Function that lets the user set all the options for the stero 
    */

    std::string inputString;
    int inputInt;
    float inputFloat;
    bool inputBool;

    do {
        input("Who is the manufacturer (generic)", inputString);
        stero->setManufacturer(inputString);

        input("What is the model (req)", inputString);
        stero->setModel(inputString);

        input("What is the serial number (req)", inputString);
        stero->setSerialNumber(inputString);

        input("Which band (AM/FM)", inputString);
        stero->setBand(inputString);

        input("What is the wattage (1-10)", inputInt);
        stero->setWattage(inputInt);

        input("How many channels (1-inf)", inputInt);
        stero->setNumChannels(inputInt);


        input("What is the volume (1-10)", inputInt);
        stero->setVolume(inputInt);

        input("What is the bass level", inputInt);
        stero->setBass(inputInt);

        input("What is the signal strength (1-100)", inputInt);
        stero->setSignal(inputInt);

        input("What is the frequency (MHz) (-inf-120)", inputFloat);
        stero->setFrequency(inputFloat);
    } while (!stero->validCheck());

}

void setSteroStatus() {
    /*
    Function that turns off or turns on the stero 
    */
    if (stero->getPower()) {
        stero->setPower(0);
        std::cout << "Powered off" << std::endl;
    } else {
        stero->setPower(1);
        std::cout << "Powered on" << std::endl;
    }
}

void steroMenu() {
    /*
    CLI Menu to change the values 
    
    */
    int userValue;
    int userChange;
    std::string options[9] = {
        "Change volume",
        "Change bass level",
        "Change signal strength",
        "Change band (AM/FM)",
        "Change frequency",
        "Change manufacturer",
        "Change model",
        "Change serial number",
        "Leave"
    };

    if (!stero->getPower()) {
        std::cout << "Error: The stero is not turned on!" << std::endl;
        return;
    }
    do {
        std::cout << "<---- STERO MENU ---->" << std::endl;
        for (int i = 0; i < 9; i++) {
            std::cout << i+1 << ": " << options[i] << std::endl;
        }
        input("[1-9]", userValue);
        switch(userValue) {
            case 1:
                input("Set volume level", userChange);
                if (userChange > 0 && userChange <= 10) {
                    stero->setVolume(userChange);
                    std::cout << "Setting volume to " << userChange << std::endl;
                } else {
                    std::cout << userChange << std::endl;
                }
                break;
            case 2:
                input("Set bass level", userChange);
                if (userChange > 0 && userChange <= 100) {
                    stero->setBass(userChange);
                    std::cout << "Setting bass to " << userChange << std::endl;
                } else {
                    std::cout << "Invalid bass level! " << userChange << std::endl;
                }
                break;

            case 3:
                input("Set signal strength", userChange);
                if (userChange >= 0 && userChange <= 100) {
                    stero->setSignal(userChange);
                    std::cout << "Setting signal strength to " << userChange << std::endl;
                } else {
                    std::cout << "Invalid signal strength!" << std::endl;
                }
                break;

            case 4:
                {
                    std::string band;
                    input("Set band (AM/FM)", band);
                    stero->setBand(band);
                    std::cout << "Setting band to " << band << std::endl;
                }
                break;

            case 5:
                {
                    float freq;
                    input("Set frequency (MHz)", freq);
                    stero->setFrequency(freq);
                    std::cout << "Setting frequency to " << freq << " MHz" << std::endl;
                }
                break;

            case 6:
                {
                    std::string manufacturer;
                    input("Set manufacturer", manufacturer);
                    stero->setManufacturer(manufacturer);
                    std::cout << "Setting manufacturer to " << manufacturer << std::endl;
                }
                break;

            case 7:
                {
                    std::string model;
                    input("Set model", model);
                    stero->setModel(model);
                    std::cout << "Setting model to " << model << std::endl;
                }
                break;

            case 8:
                {
                    std::string serial;
                    input("Set serial number", serial);
                    stero->setSerialNumber(serial);
                    std::cout << "Setting serial number to " << serial << std::endl;
                }
                break;

            case 9:
                break;
            default:
                std::cout << "Invalid option!" << std::endl;
                break;

        }
    } while (userValue != 9);
    std::cout << "Leaving Stero Menu" << std::endl;
}

int main() {
    /*
    Initilizes the script
    */
    int userValue;

    setStero();

    std::string options[5] = {
        "Create stero",
        "Go to stero menu",
        "See values",
        "Turn stero on/off",
        "Leave"
    };
    do {
    std::cout << "<---- Main Menu ---->" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << i+1 << ": " << options[i] << std::endl;
    }
    input("[1-5]", userValue);
    switch(userValue) {
        case 1: setStero(); break;
        case 2: steroMenu(); break;
        case 3: stero->display_info(); break;
        case 4: setSteroStatus(); break;
        case 5: break; 
    }

    } while (userValue != 5);
    std::cout << "Quitting..." << std::endl;


    return 0;
}