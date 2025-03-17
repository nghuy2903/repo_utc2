#include <iostream>
#include <cstring>

using namespace std;

char* Copy(const char *s){
    return strcpy(new char[strlen(s)+1], s);
}

class String{
    private:
        char *s;
    public:
        String(const char *x = ""){
            s = Copy(x);
        }
        ~String(){
            delete[] s;
        }
        void inPut();
        void outPut();
        int Lenght() const;
        int compare(const String& other) const; // Hàm so sánh 2 chuỗi
        void toUpper();//Hàm in thường
        void toLower();// Hàm in hoa
        void capitalize();// Hàm chuẩn hóa
        void removeExtraSpaces(); // Hàm xóa khoảng trắng
        String concatenate(const String& other) const; // Hàm nối chuỗi
        String reverse() const;// Hàm đảo chuỗi
};

void String::inPut(){
    const int maxS = 1000;
    s = new char[maxS];
    cout << "Nhap chuoi: ";
    cin.getline(s, maxS);
}

void String::outPut(){
    cout << s << endl;
}

int String::Lenght() const{
    return strlen(s);
}

int String::compare(const String& other) const{
    return strcmp(s, other.s);
}

void String::toUpper(){
    for (int i = 0; s[i]; i++) {
        s[i] = toupper(s[i]);
    }
}

void String::toLower(){
    for (int i = 0; s[i]; i++) {
        s[i] = tolower(s[i]);
    }
}

void String::capitalize(){
    // Capitalize first letter of each word
    bool capitalizeNext = true;
    for (int i = 0; s[i]; i++) {
        if (isspace(s[i])) {
            capitalizeNext = true;
        } else if (capitalizeNext) {
            s[i] = toupper(s[i]);
            capitalizeNext = false;
        } else {
            s[i] = tolower(s[i]);
        }
    }
}

void String::removeExtraSpaces(){
    // Remove extra spaces
    int j = 0;
    bool spaceFound = false;
    for (int i = 0; s[i]; i++) {
        if (isspace(s[i])) {
            if (!spaceFound) {
                s[j++] = ' ';
                spaceFound = true;
            }
        } else {
            s[j++] = s[i];
            spaceFound = false;
        }
    }
    s[j] = '\0';
}

String String::concatenate(const String& other) const{
    char* result = new char[Lenght() + other.Lenght() + 1];
    strcpy(result, s);
    strcat(result, other.s);
    return String(result);
}

String String::reverse() const{
    char* reversed = new char[Lenght() + 1];
    int j = 0;
    for (int i = Lenght() - 1; i >= 0; i--) {
        reversed[j++] = s[i];
    }
    reversed[j] = '\0';
    return String(reversed);
}

int main(){
    String P;
    P.inPut();

    cout << "Chuoi ban dau: ";
    P.outPut();

    cout << "Chieu dai chuoi: " << P.Lenght() << endl;

    String Q;
    Q.inPut();

    cout << "Chuoi thu hai: ";
    Q.outPut();

    if (P.compare(Q) == 0) {
        cout << "Hai chuoi giong nhau." << endl;
    } else {
        cout << "Hai chuoi khac nhau." << endl;
    }

    String concatenated = P.concatenate(Q);
    cout << "Chuoi sau khi noi: ";
    concatenated.outPut();

    String reversed = P.reverse();
    cout << "Chuoi sau khi dao nguoc: ";
    reversed.outPut();

    P.toUpper();
    cout << "Chuoi sau khi chuyen sang chu hoa: ";
    P.outPut();

    P.toLower();
    cout << "Chuoi sau khi chuyen sang chu thuong: ";
    P.outPut();

    P.capitalize();
    cout << "Chuoi sau khi chuan hoa: ";
    P.outPut();

    P.removeExtraSpaces();
    cout << "Chuoi sau khi xoa khoang trang du thua: ";
    P.outPut();

    return 0;
}
