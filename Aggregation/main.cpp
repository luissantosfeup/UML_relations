#include <iostream>
#include <string>

class Speaker {
public:
    Speaker(const std::string& name) : name(name) {}

    void playSound(const std::string& sound) {
        std::cout << "Speaker '" << name
                  << "' is playing: " << sound
                  << std::endl;
    }

private:
    std::string name;
};

class Radio {
public:
    Radio() {
        // Initialize the radio
    }

    void tuneToStation(const std::string& station) {
        std::cout << "Tuned to radio station: "
                  << station << std::endl;
    }
};

class Car {
public:
    Car(const std::string& model) : model(model), radio(nullptr), speaker(nullptr) {
        // The Car class does not create Radio and Speaker instances in the constructor
    }

    void installRadio(Radio* radio) {
        this->radio = radio;
    }

    void installSpeaker(Speaker* speaker) {
        this->speaker = speaker;
    }

    void playMusic(const std::string& station, const std::string& music) {
        if (radio) {
            radio->tuneToStation(station);
        }
        if (speaker) {
            speaker->playSound(music);
        }
    }

private:
    std::string model;
    Radio* radio;    // Aggregation: Car may or may not have a radio
    Speaker* speaker;// Aggregation: Car may or may not have a speaker
};

int main() {
    Car myCar("Fiat");

    // Car exists without Radio and Speaker initially
    myCar.playMusic("FM 101.3", "Nova Era"); // No radio or speaker initially

    // Later, we can add Radio and Speaker as needed
    Radio carRadio;
    Speaker carSpeaker("Car Speaker");

    myCar.installRadio(&carRadio);
    myCar.installSpeaker(&carSpeaker);

    // Now, the Car has Radio and Speaker
    myCar.playMusic("FM 101.3", "Nova Era");

    return 0;
}
