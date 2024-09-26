#include <iostream>
#include <string>

using namespace std;

class BloodType {
private:
    string bloodGroup;
    char rhFactor;

public:
    BloodType(string group, char rh) {
        bloodGroup = group;
        rhFactor = rh;
    }

    bool ValidType(string group, char rh) {
        string validGroups[] = {"A", "B", "AB", "O"};
        for (int i = 0; i < 4; ++i) {
            if (validGroups[i] == group && (rh == '+' || rh == '-')) {
                return true;
            }
        }
        return false;
    }

    bool Donate(BloodType have) {
        if (bloodGroup == "O" && rhFactor == '-') return true;
        if (bloodGroup == "O" && rhFactor == '+') return have.bloodGroup == "O" && have.rhFactor == '+';
        if (bloodGroup == "A" && rhFactor == '-') return (have.bloodGroup == "A" || have.bloodGroup == "AB") && have.rhFactor == '-';
        if (bloodGroup == "A" && rhFactor == '+') return (have.bloodGroup == "A" || have.bloodGroup == "AB");
        if (bloodGroup == "B" && rhFactor == '-') return (have.bloodGroup == "B" || have.bloodGroup == "AB") && have.rhFactor == '-';
        if (bloodGroup == "B" && rhFactor == '+') return (have.bloodGroup == "B" || have.bloodGroup == "AB");
        if (bloodGroup == "AB" && rhFactor == '-') return have.bloodGroup == "AB" && have.rhFactor == '-';
        if (bloodGroup == "AB" && rhFactor == '+') return have.bloodGroup == "AB";
        return false;
    }

    bool Receive(BloodType donor) {
        if (bloodGroup == "O" && rhFactor == '-') return donor.bloodGroup == "O" && donor.rhFactor == '-';
        if (bloodGroup == "O" && rhFactor == '+') return donor.bloodGroup == "O";
        if (bloodGroup == "A" && rhFactor == '-') return (donor.bloodGroup == "A" || donor.bloodGroup == "O") && donor.rhFactor == '-';
        if (bloodGroup == "A" && rhFactor == '+') return donor.bloodGroup == "A" || donor.bloodGroup == "O";
        if (bloodGroup == "B" && rhFactor == '-') return (donor.bloodGroup == "B" || donor.bloodGroup == "O") && donor.rhFactor == '-';
        if (bloodGroup == "B" && rhFactor == '+') return donor.bloodGroup == "B" || donor.bloodGroup == "O";
        if (bloodGroup == "AB" && rhFactor == '-') return donor.rhFactor == '-' && (donor.bloodGroup == "A" || donor.bloodGroup == "B" || donor.bloodGroup == "AB" || donor.bloodGroup == "O");
        if (bloodGroup == "AB" && rhFactor == '+') return donor.bloodGroup == "A" || donor.bloodGroup == "B" || donor.bloodGroup == "AB" || donor.bloodGroup == "O";
        return false;
    }

    string getBloodType() const {
        return bloodGroup + rhFactor;
    }
};

int main() {
    string inputBloodGroup;
    char inputRhFactor;

       cout << "Enter your blood group (A, B, AB, O): ";
    cin >> inputBloodGroup;

    cout << "Enter your Rh factor (+ or -): ";
       cin >> inputRhFactor;

    BloodType temp("A", '+');
    if (!temp.ValidType(inputBloodGroup, inputRhFactor)) {
        cout << "Invalid blood type. Please enter a valid blood group and Rh factor.\n";
        return 1;
    }

    BloodType userBlood(inputBloodGroup, inputRhFactor);

    BloodType bloodTypes[] = {
        BloodType("A", '+'),
        BloodType("A", '-'),
        BloodType("B", '+'),
        BloodType("B", '-'),
        BloodType("AB", '+'),
        BloodType("AB", '-'),
        BloodType("O", '+'),
        BloodType("O", '-')
    };

    cout << "\nYou can donate to: \n";
    for (BloodType give : bloodTypes) {
        if (userBlood.Donate(give)) {
            cout << give.getBloodType() << endl;
        }
    }

    cout << "\nYou can receive from: \n";
    for (BloodType donor : bloodTypes) {
        if (userBlood.Receive(donor)) {
            cout << donor.getBloodType() << endl;
        }
    }

    return 0;
}
