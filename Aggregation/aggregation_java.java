class Speaker {
    private String name;

    public Speaker(String name) {
        this.name = name;
    }

    public void playSound(String sound) {
        System.out.println("Speaker '" + name + "' is playing: " + sound);
    }
}

class Radio {
    public Radio() {
        // Initialize the radio
    }

    public void tuneToStation(String station) {
        System.out.println("Tuned to radio station: " + station);
    }
}

class Car {
    private String model;
    private Radio radio;
    private Speaker speaker;

    public Car(String model) {
        this.model = model;
        this.radio = null;
        this.speaker = null;
    }

    public void installRadio(Radio radio) {
        this.radio = radio;
    }

    public void installSpeaker(Speaker speaker) {
        this.speaker = speaker;
    }

    public void playMusic(String station, String music) {
        if (radio != null) {
            radio.tuneToStation(station);
        }
        if (speaker != null) {
            speaker.playSound(music);
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Car myCar = new Car("Sedan");

        // Car exists without Radio and Speaker initially
        myCar.playMusic("FM 101.5", "Rock Music"); // No radio or speaker initially

        // Later, we can add Radio and Speaker as needed
        Radio carRadio = new Radio();
        Speaker carSpeaker = new Speaker("Car Speaker");

        myCar.installRadio(carRadio);
        myCar.installSpeaker(carSpeaker);

        // Now, the Car has Radio and Speaker
        myCar.playMusic("FM 101.5", "Rock Music");
    }
}
