import java.util.*;

class Animal {
    void eat() {
        System.out.println("Animal is eating");
    }
}

class Dog extends Animal {
    void bark() {
        System.out.println("Dog is barking");
    }
}

class Cat extends Animal {
    void meow() {
        System.out.println("Cat is meowing");
    }
}

// Multilevel Inheritance
class Puppy extends Dog {
    void play() {
        System.out.println("Puppy is playing");
    }
}

// Hierarchical Inheritance
class Tiger extends Animal {
    void roar() {
        System.out.println("Tiger is roaring");
    }
}

// Multiple Inheritance through interfaces
interface AnimalInterface {
    void eat();
}

interface PetInterface {
    void play();
}

class Pet implements AnimalInterface, PetInterface {
    public void eat() {
        System.out.println("Pet is eating");
    }
    
    public void play() {
        System.out.println("Pet is playing");
    }
}

// Hybrid Inheritance (using classes and interfaces)
interface WildAnimal {
    void hunt();
}

class Lion extends Animal implements WildAnimal {
    void roar() {
        System.out.println("Lion is roaring");
    }
    
    public void hunt() {
        System.out.println("Lion is hunting");
    }
}

public class InheritanceTypes {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int choice;
        
        do {
            System.out.println("\n--- INHERITANCE TYPES MENU ---");
            System.out.println("1. Single Inheritance");
            System.out.println("2. Multilevel Inheritance");
            System.out.println("3. Hierarchical Inheritance");
            System.out.println("4. Multiple Inheritance (through interfaces)");
            System.out.println("5. Hybrid Inheritance");
            System.out.println("6. Exit");
            System.out.print("Enter your choice: ");
            choice = sc.nextInt();
            
            switch (choice) {
                case 1:
                    System.out.println("\n--- Single Inheritance ---");
                    Dog dog = new Dog();
                    dog.eat(); // inherited from Animal
                    dog.bark(); // specific to Dog
                    break;

                case 2:
                    System.out.println("\n--- Multilevel Inheritance ---");
                    Puppy puppy = new Puppy();
                    puppy.eat(); // inherited from Animal
                    puppy.bark(); // inherited from Dog
                    puppy.play(); // specific to Puppy
                    break;

                case 3:
                    System.out.println("\n--- Hierarchical Inheritance ---");
                    Tiger tiger = new Tiger();
                    tiger.eat(); // inherited from Animal
                    tiger.roar(); // specific to Tiger
                    break;

                case 4:
                    System.out.println("\n--- Multiple Inheritance (using interfaces) ---");
                    Pet pet = new Pet();
                    pet.eat(); // from AnimalInterface
                    pet.play(); // from PetInterface
                    break;

                case 5:
                    System.out.println("\n--- Hybrid Inheritance ---");
                    Lion lion = new Lion();
                    lion.eat(); // inherited from Animal
                    lion.roar(); // specific to Lion
                    lion.hunt(); // from WildAnimal interface
                    break;

                case 6:
                    System.out.println("Exiting the Inheritance Program.");
                    break;

                default:
                    System.out.println("Invalid choice, please try again.");
            }
        } while (choice != 6);
        
        sc.close();
    }
}
