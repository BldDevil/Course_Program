// Course_Program.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <Windows.h>

using namespace std;

struct Date{
    int day, month, year;
};

int ch_sub, ch_sess;

class Subject {
public:
    int ex_mark = 0;
    string mark = " ";
    string exam_type = " ";
    string _name = " ";
    void set_all() {
        set_name();
        set_type();
        set_evaluation();
    }
    void set_name() {
        cout << "Введите название дисциплины: ";
        cin.ignore();
        getline(cin, _name);
    }
    void set_type() {
        cout << "Введите тип аттестации (экзамен/зачёт): ";
        cin >> exam_type;
        if (exam_type != "экзамен" and exam_type != "зачёт"){
            system("cls");
            set_type();
        }
    }
    void set_evaluation() {
        if (exam_type == "экзамен") {
            cout << "Введите отметку от 2 до 5: \n";
            cin >> ex_mark;
            if (ex_mark < 2 or ex_mark > 5) {
                system("cls");
                set_evaluation();
             
            }
            mark = "";
        }
        else {
            if (exam_type == "зачёт") {
                cout << "Введите отметку о зачёте (зачёт/незачёт): \n";
                cin >> mark;
            }
            ex_mark = 0;
        }
    }
    void get_info() {
        get_name();
        cout << ' ';
        get_mark();
    }
    void get_name() {
        cout << _name;
    }
    void get_type() {
        cout << exam_type;
    }
    void get_mark() {
        if (exam_type == "экзамен") { cout << ex_mark; }
        else { cout << mark; };
    }
};

class Session: public Subject {
public:
    Subject subject[9];
    int redline = 0;
    void add_subject() {
        if (redline < 9) {
            subject[redline].set_all();
            redline++;
        }
        else {
            cout << "Превышено максимальное количество дисциплин в сессии" << endl;
        }
    }
    void edit_name(int number) {
        subject[number].set_name();
    }
    void edit_type(int number) {
        subject[number].set_type();
    }
    void edit_mark(int number) {
        subject[number].set_evaluation();
    }
    void get_list_subjects() {
            cout << "Список дисциплин: " << endl;
            for (int i = 1; i < 10; i++) {
                cout << i << '.' << ' ';
                subject[i - 1].get_info();
                cout << endl;
        }
    }
};

class Student: public Session {
public:
    void set_all_student() {
        set_initials();
        set_date_of_birth();
        set_gender();
        set_year_of_application();
        set_rec_book();
        set_faculty();
        set_department();
        set_group();
    }
    void Date_birth_out() {
        if (((0 < date_of_birth.day) and (date_of_birth.day < 10)) or ((0 < date_of_birth.month) and (date_of_birth.month < 10))) {
            cout << "Дата рождения: ";
            if (date_of_birth.day < 10) {
                cout << '0' << date_of_birth.day << '.';
            }
            else {
                cout << date_of_birth.day << '.';
            }
            if (date_of_birth.month < 10) {
                cout << '0' << date_of_birth.month << '.';
            }
            else {
                cout << date_of_birth.month << '.';
            }
            cout << date_of_birth.year << endl;
        }
        else {
            cout << "Дата рождения: " << date_of_birth.day << "." << date_of_birth.month << "." << date_of_birth.year << endl;
        }
    }
    void set_surname() {
        cout << "Введите фамилию студента: ";
        cin >> surname;
    }
    void set_name() {
        cout << "Введите имя студента: ";
        cin >> name;
    }
    void set_patronymic() {
        cout << "Введите отчество студента: ";
        cin >> patronymic;
    }
    void set_initials() {
        cout << "Введите фамилию, имя и отчество студента: ";
        cin >> surname >> name >> patronymic;
    }
    void set_date_of_birth() {
        cout << "Введите дату рождения студента в формате дд.мм.гггг: ";
       // cin >> date_of_birth.day >> date_of_birth.month >> date_of_birth.year;
        scanf_s("%d.%d.%d", &date_of_birth.day, &date_of_birth.month, &date_of_birth.year);
    }
    void set_gender() {
        cout << "Введите пол студента: ";
        cin >> gender;
    }
    void set_year_of_application() {
        cout << "Введите год поступления студента: ";
        cin >> year_of_application;
    }
    void set_rec_book() {
        cout << "Введите шифр студента: ";
        cin >> num_of_record_book;
    }
    void set_faculty() {
        cout << "Введите институт, в котором обучается студент: ";
        cin.ignore();
        getline(cin, faculty, '\n');
    }
    void set_department() {
        cout << "Введите кафедру института: ";
        cin.ignore();
        getline(cin, department, '\n');
    }
    void set_group() {
        cout << "Введите название группы студента: ";
        cin >> group;
    }
    void print_info() {
        cout << "Студент: " << surname << " " << name << " " << patronymic << endl;
        Date_birth_out();
        cout << "Пол: " << gender << endl;
        cout << "Номер зачётной книжки: " << num_of_record_book << endl;
        cout << "Год поступления: " << year_of_application << endl;
        cout << "Институт: " << faculty << endl;
        cout << "Кафедра: " << department << endl;
        cout << "Группа: " << group << endl;
    }
    void get_session() {
        system("cls");
        for (int i = 1; i < 9; i++) {
            cout << "Сессия " << " " << i << endl;
        }
    }

    void session_panel() {
        int sess;
        cout << "Выберите сессию: ";
        cin >> sess;
        if ((sess < 0) or (sess > 8)) {
            cout << "Неверный номер сессии";
            session_panel();
        }
        else {
            system("cls");
            ch_sess = sess - 1;
            session[ch_sess].get_list_subjects();
        }
    }
    Session session[8];
    string surname, name, patronymic;
    char gender;
    string faculty, department, group, num_of_record_book;
    Date date_of_birth;
    int year_of_application;
};

struct Node {
    Student st;
    Node* next;
};

int students_count = 0;

class ClassList {
public:

    Node* head;
    Node* chosen;


    void save_to_db() {
        ofstream db_out("database", ios_base::out | ios_base::binary);
        Node* curr = head;
        db_out << students_count << endl;
        while (curr) {
            db_out << curr->st.surname << endl << curr->st.name << endl << curr->st.patronymic << endl;
            db_out << curr->st.date_of_birth.day << endl << curr->st.date_of_birth.month << endl << curr->st.date_of_birth.year << endl;
            db_out << curr->st.gender << endl << curr->st.num_of_record_book << endl << curr->st.year_of_application << endl << curr->st.faculty << endl;
            db_out << curr->st.department << endl << curr->st.group << endl;;
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 9; j++) {
                    db_out << curr->st.session[i].subject[j]._name << endl << curr->st.session[i].subject[j].exam_type;
                    db_out << endl << curr->st.session[i].subject[j].ex_mark << endl << curr->st.session[i].subject[j].mark << endl;
                }
            }
            curr = curr->next;
        }
        db_out.close();
    }

    void read_db() {
        ifstream db_in("database", ios_base::in | ios_base::binary);
        int st_count = 0;
        db_in >> students_count;
        for (int i = 0; i < students_count; i++) {
            Student term;
            db_in >> term.surname >> term.name >> term.patronymic >> term.date_of_birth.day >> term.date_of_birth.month >> term.date_of_birth.year >> term.gender >> term.num_of_record_book >> term.year_of_application;
            db_in.ignore();
            getline(db_in, term.faculty, '\n');
            getline(db_in, term.department, '\n');
            getline(db_in, term.group, '\n');
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 9; j++) {
                    getline(db_in, term.session[i].subject[j]._name, '\n');
                    getline(db_in, term.session[i].subject[j].exam_type, '\n');
                    db_in >> term.session[i].subject[j].ex_mark; db_in.ignore();
                    getline(db_in, term.session[i].subject[j].mark, '\n');
                }
            }
            Node* newItem = new Node();
            newItem->st = term;
            if (students_count == 0) {
                newItem->next = NULL;
            }
            else {
                newItem->next = head;
            }
            head = newItem;
            st_count++;
        }
        db_in.close();
        students_count = st_count;
    }

    void add_student_to_list()
    {
        Student st;
        st.set_all_student();
        Node* newItem = new Node();
        newItem->st = st;
        if (students_count == 0)
            newItem->next = NULL;
        else
            newItem->next = head;
        head = newItem;
        cout << endl;
        students_count++;
        save_to_db();
        cin.ignore();
    }

    int findIndex(Node* st) {
        Node* current = new Node();
        current = head;
        for (int i = 0; i < students_count; i++) {
            if (current->st.num_of_record_book == chosen->st.num_of_record_book) {
                return i;
            };
            current = current->next;
        }

    }

    void delete_student(int index) {
        if (index >= 0 and index < students_count and students_count>0) {
            Node* current = head;
            struct Node* old;
            if (index == 0) {
                old = head;
                head = current->next;
                delete old;
                students_count--;
            }
            else {
                int i = 0;
                while (current) {
                    if (i == index - 1) {
                        old = current->next->next;
                        delete current->next;
                        current->next = old;
                        students_count--;
                        break;
                    }
                    i++;
                    current = current->next;
                }
            }
        }
    }

    void delete_list(ClassList list) {
        Node* current = list.head;
        struct Node* old;
        while (current) {
            old = current->next->next;
            delete current->next;
            current->next = old;
            break;
            current = current->next;
        }
        delete list.chosen;
        delete list.head;
    }
 

    void print_list() {
        Node* current = head;
        while (current) {
            current->st.print_info();
            current = current->next;
            cout << endl;
        }
    }
};

ClassList list;

class Menu{
public:
    void count_of_students() {
        cout << "Кол-во студентов в базе: " << students_count << endl;
    }

    void menu_interface() {
        cout << "Список доступных команд:" << endl << "1. Просмотреть базу данных" << endl << "2. Добавить студента" << endl;
        cout << "3. Посмотреть информацию о конкретном студенте" << endl << "4. Выполнить задание " << endl << "0. Завершить программу" << endl << endl;
    }

    void menu_2_interface() {
        cout << "Список доступных команд:" << endl << "1. Редактировать данные " << endl << "2. Просмотреть оценки" << endl << "3. Удалить студента" << endl << "4. Выйти" << endl << endl;
    }

    void subject_interface() {
        cout << "Список команд:" << endl << "1. Обновить дисциплину" << endl << "2. Изменить название дисциплины" << endl << "3. Изменить оценку" << endl << "4. Изменить тип аттестации" << endl << "5. Удалить дисциплину" << endl;
        cout << "6. Выйти" << endl;
    }

    void subjects_list_interface() {
        cout << "Список команд:" << endl << "1. Просмотреть дисциплину" << endl << "2. Выйти" << endl;
    }

    void subject_info(int ch_sub) {
        cout << "Название дисциплины: ";
        list.chosen->st.session[ch_sess].subject[ch_sub - 1].get_name();
        cout << endl;
        cout << "Тип аттестации: ";
        list.chosen->st.session[ch_sess].subject[ch_sub - 1].get_type();
        cout << endl;
        cout << "Оценка: ";
        list.chosen->st.session[ch_sess].subject[ch_sub - 1].get_mark();
        cout << endl;
    }

    void subjects_panel(int ch_sess) {
        cout << "Выберите дисциплину согласно номеру в списке: ";
        cin >> ch_sub;
        if (ch_sub < 1 or ch_sub > 9) {
            cout << "Данной дисциплины нет в списке" << endl;
            subjects_panel(ch_sess);
        }
        else {
            system("cls");
            subject_info(ch_sub);
            control_subject(ch_sub - 1);
        }
    }

    void control_subjects_list() {
        int ch = 0;
        cin.ignore();
        cin >> ch;
        if (ch == 1) {
            subjects_panel(ch_sess);
        }
        if (ch == 2) {
            system("cls");
            control_student(list.chosen);
        }
        else {
            system("cls");
            list.chosen->st.session[ch_sess].get_list_subjects();
            subjects_list_interface();
            control_subjects_list();
        }
    }

    void control_subject(int n) {
        subject_interface();
        cin.ignore();
        int ch;
        cin >> ch;
        if (ch == 1) {
            list.chosen->st.session[ch_sess].subject[n].set_name();
            list.chosen->st.session[ch_sess].subject[n].set_type();
            list.chosen->st.session[ch_sess].subject[n].set_evaluation();
        }
        if (ch == 2) {
            list.chosen->st.session[ch_sess].subject[n].set_name();
        }
        if (ch == 3) {
            list.chosen->st.session[ch_sess].subject[n].set_evaluation();
        }
        if (ch == 4) {
            list.chosen->st.session[ch_sess].subject[n].set_type();
        }
        if (ch == 5) {
            string ch;
            cout << "Вы уверены, что хотите удалить дисциплину? (Да/Нет) ";
            cin >> ch;
            if (ch == "Да" or ch == "да") {
                    list.chosen->st.session[ch_sess].subject[n]._name = "";
                    list.chosen->st.session[ch_sess].subject[n].exam_type = "";
                    list.chosen->st.session[ch_sess].subject[n].ex_mark = 0;
                    list.chosen->st.session[ch_sess].subject[n].mark = "";
            }
        }
        if (ch == 6) {
            system("cls");
            list.chosen->st.session[ch_sess].get_list_subjects();
            subjects_list_interface();
            control_subjects_list();
        }
        else {
            system("cls");
            subject_info(ch_sub);
            control_subject(n);
        }
  
    }

    void find_by_number() {
        cout << "Введите шифр студента: ";
        string target;
        cin >> target;
        cin.clear();
        Node* current = new Node();
        current = list.head;
        int fnd = 0;
        for (current; current != NULL; current = current->next) {
            if (current->st.num_of_record_book == target) {
                fnd = 1;
                list.chosen = current;
                list.findIndex(list.chosen);
                control_student(list.chosen);
            };
        }
        if (fnd == 0) {
            cout << "Данного студента нет в базе. Желаете добавить? (Да/Нет) ";
            string choice;
            cin >> choice;
            if (choice == "Да") {
                list.add_student_to_list();
            }
            else {
                control_main();
            }
        }
    }

    void control_student(Node* current) {
        current->st.print_info();
        int fl1 = 1;
        while (fl1) {
            char a = 0;
            menu_2_interface();
            cin >> a;
            if (a == '1') {
                cout << "Выберите данные, требующие корректировки: ";
                string dat;
                cin.ignore();
                getline(cin, dat, '\n');
                if (dat == "Фамилия") {
                    current->st.set_surname();
                }
                if (dat == "Имя") {
                    current->st.set_name();
                }
                if (dat == "Отчество") {
                    current->st.set_patronymic();
                }
                if (dat == "Дата рождения") {
                    current->st.set_date_of_birth();
                }
                if (dat == "Пол") {
                    current->st.set_gender();
                }
                if (dat == "Год поступления") {
                    current->st.set_year_of_application();
                }
                if (dat == "Номер зачетной книжки") {
                    current->st.set_rec_book();
                }
                if (dat == "Институт") {
                    current->st.set_faculty();
                }
                if (dat == "Кафедра") {
                    current->st.set_department();
                }
                if (dat == "Группа") {
                    current->st.set_group();
                }
                list.save_to_db();
                system("cls");
                current->st.print_info();
            }
            if (a == '2') {
                current->st.get_session();
                current->st.session_panel();
                subjects_list_interface();
                control_subjects_list();
            }
            if (a == '3') {
                cout << "Вы уверены, что хотите удалить студента из БД? (Да/Нет) ";
                string choice;
                cin >> choice;
                if (choice == "Да") {
                    list.delete_student(list.findIndex(list.chosen));
                    cout << "Данные о студенте успешно удалены.";
                    Sleep(2000);
                    system("cls");
                    control_main();
                }
                else { system("cls"); list.chosen->st.print_info(); };
            }
            if (a == '4') {
                system("cls");
                control_main();
            }
            else {
                system("cls");
                control_student(current);
            }
        }

    }

    void solve_task() {
        cout << "Вы приступили к решению индивидуального задания. Выберите сессию, по которой будут сортироваться студенты: ";
        int sess_choice = 0;
        cin >> sess_choice;
        if (sess_choice < 1 or sess_choice > 9) {
            cout << "Некорректный номер сессии" << endl;
            Sleep(1000);
            solve_task();
        }
        else {
        a:     int start, end;
            cout << "Введите интервал, в пределах которого будут отсортированы студенты (год рождения)" << endl;
            cout << "Начало: ";
            cin >> start;
            if (start < 1900 or start > 2100) {
                cout << "Некорректная дата рождения";
                goto a;
            }
      b:    cout << endl << "Конец: ";
            cin >> end;
            if (end < 1900 or end > 2100) {
                cout << "Некорректная дата рождения";
                goto b;
            }
            else {
                Node* five_st = new Node[students_count];
                int five_head = 0;

                Node* four_st = new Node[students_count];
                int four_head = 0;

                Node* three_st = new Node[students_count];
                int three_head = 0;

                Node* curr = list.head;
                for (curr; curr != NULL; curr = curr->next) {
                    if ((curr->st.date_of_birth.year >= start) and (curr->st.date_of_birth.year <= end)) {
                        int five = 0; int four = 0; int three = 0;
                        for (int i = 0; i < 9; i++) {
                            if (curr->st.session[sess_choice - 1].subject[i].ex_mark == 5) {
                                five++;
                            }
                            if (curr->st.session[sess_choice - 1].subject[i].ex_mark == 4) {
                                four++;
                            }
                            if (curr->st.session[sess_choice - 1].subject[i].ex_mark == 3) {
                                three++;
                            }
                        }
                        if ((four == 0) and (three == 0) and (five > 0)) {
                            five_st[five_head] = *curr;
                            five_head++;
                        }
                        if ((five > 0) and (four > 0) and (three == 0)) {
                            four_st[four_head] = *curr;
                            four_head++;
                        }
                        if ((five == 0) and (four == 0) and (three > 0)) {
                            three_st[three_head] = *curr;
                            three_head++;
                        }
                    }
                }
                cout << "Отличники: " << endl;
                for (int i = 0; i <= five_head; i++) {
                    cout << five_st[i].st.surname << ' ' << five_st[i].st.name << ' ' << five_st[i].st.patronymic << endl;
                }
                cout << endl << "Хорошисты: " << endl;
                for (int i = 0; i <= four_head; i++) {
                    cout << four_st[i].st.surname << ' ' << four_st[i].st.name << ' ' << four_st[i].st.patronymic << endl;

                }
                cout << endl << "Троечники: " << endl;
                for (int i = 0; i <= three_head; i++) {
                    cout << three_st[i].st.surname << ' ' << three_st[i].st.name << ' ' << three_st[i].st.patronymic << endl;
                }
                delete[] five_st;
                delete[] four_st;
                delete[] three_st;
                delete[] curr;
            }
        }
    }


    void control_main() {
        int fl = 1;
        while (fl) {
            cout << "Вас приветствует СУБД студентов РТУ МИРЭА" << endl;
            count_of_students();
            menu_interface();
            string a;
            cin >> a;
            system("cls");
            if (a == "1") {
                list.print_list();
            }
            if (a == "2") {
                list.add_student_to_list();
            }
            if (a == "3") {
                find_by_number();
            }
            if (a == "4") {
                solve_task();
            }
            if (a == "0") {
                list.save_to_db();
                list.delete_list(list);
                exit(0);
            }
        }
    }
};

int main()
{
    SetConsoleCP(1251); SetConsoleOutputCP(1251);
    list.read_db();
    Menu menu;
    menu.control_main();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
