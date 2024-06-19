#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define password 12345

// declaring structure for people  
typedef struct { 
    char FirstName[30];
    char LastName[30];
    char PhoneNumber[30];
    int Age; 
    int MaximumAllowedBooks;
} Person;

// declaring structure for books
typedef struct { 
    char Name[30];
    char Author[30];
    char Genre[30];
    int Number_of_pages; 
    int Year_of_publication; 
    int is_borrowed;    
} Book; 

// declaring structure for borrow records
typedef struct { 
    int is_returned;
    Book* borrowed_book; 
    Person* borrower_person; 
} Borrow;

int person_num = 0;
int book_num = 0;
int borrow_num = 0;

Person p[100];
Book b[1000];
Borrow borrow[10000];

void load_data();
void save_data();

void write_people_to_file() 
{
    FILE *person_file = fopen("person.txt", "+a");
    if (person_file  == NULL) {
        printf("Error opening %s for writing.\n", "person.txt");
        exit(-1);
    }

    for (int i = 0; i < person_num; ++i) {
        fprintf(person_file, "Person %d:\n", i + 1);
        fprintf(person_file, "First Name: %s\n", p[i].FirstName);
        fprintf(person_file, "Last Name: %s\n", p[i].LastName);
        fprintf(person_file, "Phone Number: %s\n", p[i].PhoneNumber);
        fprintf(person_file, "Age: %d\n", p[i].Age);
        fprintf(person_file, "Maximum Allowed Books: %d\n\n", p[i].MaximumAllowedBooks);
    }
    fclose(person_file);
}

void read_people_from_file() 
{
    FILE *person_file = fopen("person.txt", "r");
    if (person_file == NULL) {
        printf("Error opening %s for reading.\n","person.txt");
        return;
    }
    char buffer[100];
    int j = 0;
    while (fgets(buffer, 100, person_file) != NULL && j < person_num) {
        if (strncmp(buffer, "Person", 6) == 0) {
            // Skip "Person n:" line
            fgets(buffer, 100, person_file);
            sscanf(buffer, "First Name: %[^\n]", p[j].FirstName);
            fgets(buffer, 100, person_file);
            sscanf(buffer, "Last Name: %[^\n]", p[j].LastName);
            fgets(buffer, 100, person_file);
            sscanf(buffer, "Phone Number: %[^\n]", p[j].PhoneNumber);
            fgets(buffer, 100, person_file);
            sscanf(buffer, "Age: %d", &p[j].Age);
            fgets(buffer, 100, person_file);
            sscanf(buffer, "Maximum Allowed Books: %d", &p[j].MaximumAllowedBooks);
            j++;
        }
    }
    fclose(person_file);

    // Print the read information
    for (int i = 0; i < person_num; ++i) {
        printf("Person %d:\n", i + 1);
        printf("First Name: %s\n", p[i].FirstName);
        printf("Last Name: %s\n", p[i].LastName);
        printf("Phone Number: %s\n", p[i].PhoneNumber);
        printf("Age: %d\n", p[i].Age);
        printf("Maximum Allowed Books: %d\n\n", p[i].MaximumAllowedBooks);
    }
}

void write_books_to_file() 
{
    FILE *books_file = fopen("book.txt", "a+");
    if (books_file  == NULL) {
        printf("Error opening %s for writing.\n", "book.txt");
        exit(-1);
    }

    for (int i = 0; i < book_num; ++i) {
        fprintf(books_file, "Book %d:\n", i + 1);
        fprintf(books_file, "Name: %s\n", b[i].Name);
        fprintf(books_file, "Author: %s\n", b[i].Author);
        fprintf(books_file, "Genre: %s\n", b[i].Genre);
        fprintf(books_file, "Number_of_pages: %d\n", b[i].Number_of_pages);
        fprintf(books_file, "Year_of_publication: %d\n", b[i].Year_of_publication);
        fprintf(books_file, "is_borrowed: %d\n\n", b[i].is_borrowed);
    }
    fclose(books_file); 
}

void read_books_from_file() 
{
    FILE *books_file = fopen("book.txt", "r");
    if (books_file == NULL) {
        printf("Error opening %s for reading.\n","book.txt");
        return;
    }
    char buffer[100];
    int j = 0;
    while (fgets(buffer, 100, books_file) != NULL && j < book_num) 
    {
        if (strncmp(buffer, "Book", 4) == 0) {
            // Skip "Person n:" line
            fgets(buffer, 100, books_file);
            sscanf(buffer, "Name: %[^\n]", b[j].Name);
            fgets(buffer, 100, books_file);
            sscanf(buffer, "Author: %[^\n]", b[j].Author);
            fgets(buffer, 100, books_file);
            sscanf(buffer, "Genre: %[^\n]", b[j].Genre);
            fgets(buffer, 100, books_file);
            sscanf(buffer, "Number_of_pages: %d", &b[j].Number_of_pages);
            fgets(buffer, 100, books_file);
            sscanf(buffer, "Year_of_publication: %d", &b[j].Year_of_publication);
            fgets(buffer, 100, books_file);
            sscanf(buffer, "is_borrowed: %d", &b[j].is_borrowed);
            j++;
        }
    }
    fclose(books_file);

    // Print the read information
    for (int i = 0; i < book_num; ++i) 
    {

        printf("Book %d:\n", i + 1);
        printf("Name: %s\n", b[i].Name);
        printf("Author: %s\n", b[i].Author);
        printf("Genre: %s\n", b[i].Genre);
        printf("Number_of_pages: %d\n", b[i].Number_of_pages);
        printf("Year_of_publication: %d\n", b[i].Year_of_publication);
        printf("is_borrowed: %d\n\n", b[i].is_borrowed);


    }
}

void write_borrows_to_file() 
{
    FILE *borrow_file = fopen("borrow.txt", "a+");
    if (borrow_file  == NULL) {
        printf("Error opening %s for writing.\n", "borrow.txt");
        exit(-1);
    }

    for (int i = 0; i < borrow_num; ++i) {
        fprintf(borrow_file, "Borrow %d:\n", i + 1);
        fprintf(borrow_file, "borrowed_book: %s\n", borrow[i].borrowed_book->Name);
        fprintf(borrow_file, "borrower_person: %s %s\n", borrow[i].borrower_person->FirstName,borrow[i].borrower_person->LastName);
        fprintf(borrow_file, "is_returned: %d\n\n", borrow[i].is_returned);
    }
    fclose(borrow_file);

}

void read_borrows_from_file() 
{
    FILE *borrow_file = fopen("borrow.txt", "r");
    if (borrow_file == NULL) {
        printf("Error opening %s for reading.\n","borrow.txt");
        return;
    }
    char buffer[100];
    int j = 0;
    while (fgets(buffer, 100, borrow_file) != NULL && j < borrow_num) 
    {
        if (strncmp(buffer, "Borrow", 6) == 0) {
            // Skip "Person n:" line
            fgets(buffer, 100, borrow_file);
            sscanf(buffer, "borrowed_book: %[^\n]", borrow[j].borrowed_book->Name);
            fgets(buffer, 100, borrow_file);
            sscanf(buffer, "borrower_person: %[^\n]", borrow[j].borrower_person->FirstName,borrow[j].borrower_person->LastName);
            fgets(buffer, 100, borrow_file);
            sscanf(buffer, "is_returned: %d", &borrow[j].is_returned);
            j++;
        }
    }
    fclose(borrow_file);

    // Print the read information
    for (int i = 0; i < borrow_num; ++i) 
    {
        printf("Book %d:\n", i + 1);
        printf("borrowed_book: %s\n", borrow[i].borrowed_book->Name);
        printf("borrower_person: %s %s\n", borrow[i].borrower_person->FirstName,borrow[j].borrower_person->LastName);
        printf("is_returned: %d\n\n", &borrow[i].is_returned);
    }
}


void remove_newline(char *str);
int Allnamevalidation(char *str);
int phonevalidation(char *str);
void Add_a_person();
void Add_a_book();
void part_3_menu();
int find_by_phone(char *str);
int if_book_exist(char *str);
void Add_a_borrow();
void search_book_status();
void see_A_persons_borrowed_books();
void ReturnBook();
void clear_input_buffer();

int main() {

    
    int input_password;

    printf("Welcome, password please: ");
    scanf("%d", &input_password);
    clear_input_buffer();

    if (input_password == password) 
    {
        //read_people_from_file();
        load_data();
        int desired_function;

        while (1) 
        {
            printf("What do you want to do?\n1-Add a person\n2-Add a Book\n3-Borrowing process\n0-Exit\n");
            scanf("%d", &desired_function);
            clear_input_buffer();

            switch (desired_function) {
                case 1:
                    Add_a_person();
                    person_num++;
                    break;
                case 2:
                    Add_a_book();
                    book_num++;
                    break;
                case 3:
                    part_3_menu();
                    break;
                case 0:
                    printf("Exiting...\n");
                    write_people_to_file();
                    write_books_to_file();
                    write_borrows_to_file();
                    return 0;
                default:
                    printf("Please enter a valid value.\n");
                    break;
            }
        }
    } 
    else 
    {
        printf("Wrong password. Exiting.\n");
    }

    write_people_to_file();
    write_books_to_file();
    write_borrows_to_file();
    return 0;
}

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void load_data() 
{
    FILE *file;
    // Load people data
    file = fopen("person.txt", "r");
    if (file != NULL) {
        int index;
        while (fscanf(file,"Person %d:\nFirst Name: %s\nLast Name: %s\nPhone Number: %s\nAge: %d\nMaximum Allowed Books: %d\n\n", index,p[person_num].FirstName, p[person_num].LastName, p[person_num].PhoneNumber, &p[person_num].Age, &p[person_num].MaximumAllowedBooks) != EOF) {
            person_num++;
        }
        fclose(file);
    }

    // Load books data
    file = fopen("book.txt", "r");
    if (file != NULL) {
        int bookindex;
        while (fscanf(file,"Book %d:\nName: %s\nAuthor: %s\nGenre: %s\nNumber_of_pages: %d\nYear_of_publication: %d\nis_borrowed: %d\n\n",bookindex, b[book_num].Name, b[book_num].Author, b[book_num].Genre, &b[book_num].Number_of_pages, &b[book_num].Year_of_publication, &b[book_num].is_borrowed) != EOF) {
            book_num++;
        }
        fclose(file);
    }

    // Load borrow data
    file = fopen("borrow.txt", "r");
    if (file != NULL) {
        int borrowindex;
        char book_name[30], phone_number[30];
        while (fscanf(file, "Borrow %d:\nborrowed_book: %s\nborrower_person: %s %s\nis_returned: %d\n\n",borrowindex, book_name, phone_number, &borrow[borrow_num].is_returned) != EOF) {
            int book_index = if_book_exist(book_name);
            int person_index = find_by_phone(phone_number);
            if (book_index != -1 && person_index != -1) {
                borrow[borrow_num].borrowed_book = &b[book_index];
                borrow[borrow_num].borrower_person = &p[person_index];
                borrow_num++;
            }
        }
        fclose(file);
    }
}

void remove_newline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

int Allnamevalidation(char *str) {
    size_t len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (!((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z') || str[i] == ' ')) {
            return 0;
        }
    }
    return 1;
}

int phonevalidation(char *str)
{
    //size_t len = strlen (str);
    for (int i = 0; i < 4; i++)
    {
        if (!(str[i] >= '0' && str[i] <= '9'))
        {
          return 0;  
        }
    }
    if (str[4]!= ' ')
    {
        return 0;  
    }
    
    for (int i = 5; i < 8; i++)
    {
        if (!(str[i] >= '0' && str[i] <= '9'))
        {
          return 0;  
        }
    }
    if (str[8]!= ' ')
    {
        return 0;  
    }
    for (int i = 9; i < 12; i++)
    {
        if (!(str[i] >= '0' && str[i] <= '9'))
        {
          return 0;  
        }
    }
    
    return 1;
}

void Add_a_person() {
    char intererd_FirstName[30];
    char intered_LastName[30];
    char intered_PhoneNumber[30];
    int intered_Age; 
    int intered_MaximumAllowedBooks;

    printf("Enter the required information for the new person:\n");

    // First Name
    int name_is_valid = 0;
    printf("First Name:\n");
    while (name_is_valid == 0) {
        fgets(intererd_FirstName, 30, stdin);
        remove_newline(intererd_FirstName);
        name_is_valid = Allnamevalidation(intererd_FirstName);

        if (name_is_valid == 1) {
            strcpy(p[person_num].FirstName, intererd_FirstName);
        } else {
            printf("Your input includes invalid characters. Try again:\n");
        }
    }

    // Last Name
    int lastname_is_valid = 0;
    printf("Last Name:\n");
    while (lastname_is_valid == 0) {
        fgets(intered_LastName, 30, stdin);
        remove_newline(intered_LastName);
        lastname_is_valid = Allnamevalidation(intered_LastName);

        if (lastname_is_valid == 1) {
            strcpy(p[person_num].LastName, intered_LastName);
        } else {
            printf("Your input includes invalid characters. Try again:\n");
        }
    }

    // Phone number
    int phone_is_valid = 0;
    printf("Phone number:\n");
    while (phone_is_valid == 0) {
        fgets(intered_PhoneNumber, 30, stdin);
        remove_newline(intered_PhoneNumber);
        phone_is_valid = phonevalidation(intered_PhoneNumber);

        if (phone_is_valid == 1) {
            strcpy(p[person_num].PhoneNumber, intered_PhoneNumber);
        } else {
            printf("Your input includes invalid characters. Try again:\n");
        }
    }

    // Age
    int age_success = 0;
    printf("Age:\n");
    while (age_success == 0) {
        scanf("%d", &intered_Age);
        clear_input_buffer();
        if (intered_Age >= 1 && intered_Age <= 180) {
            age_success = 1;
            p[person_num].Age = intered_Age;
        } else {
            printf("Your input is invalid. Try again:\n");
        }
    }

    // Maximum allowed books
    int maxbook_success = 0;
    printf("Maximum allowed books:\n");
    while (maxbook_success == 0) {
        scanf("%d", &intered_MaximumAllowedBooks);
        clear_input_buffer();
        if (intered_MaximumAllowedBooks >= 1 && intered_MaximumAllowedBooks <= 1000) {
            maxbook_success = 1;
            p[person_num].MaximumAllowedBooks = intered_MaximumAllowedBooks;
        } else {
            printf("Your input is invalid. Try again:\n");
        }
    }

    // Success message
    printf("%s %s's information is saved in the system!\n", p[person_num].FirstName, p[person_num].LastName);
}

void Add_a_book() {
    char intererd_Name[30];
    char intered_Author[30];
    char intered_Genre[30];
    int intered_Number_of_pages; 
    int intered_Year_of_publication;

    printf("Enter the required information for the new book:\n");

    // Name
    int name_is_valid = 0;
    printf("Name:\n");
    while (name_is_valid == 0) {
        fgets(intererd_Name, 30, stdin);
        remove_newline(intererd_Name);
        name_is_valid = Allnamevalidation(intererd_Name);

        if (name_is_valid == 1) {
            strcpy(b[book_num].Name, intererd_Name);
        } else {
            printf("Your input includes invalid characters. Try again:\n");
        }
    }

    // Author
    int author_is_valid = 0;
    printf("Author:\n");
    while (author_is_valid == 0) {
        fgets(intered_Author, 30, stdin);
        remove_newline(intered_Author);
        author_is_valid = Allnamevalidation(intered_Author);

        if (author_is_valid == 1) {
            strcpy(b[book_num].Author, intered_Author);
        } else {
            printf("Your input includes invalid characters. Try again:\n");
        }
    }

    // Genre
    int genre_is_valid = 0;
    printf("Genre:\n");
    while (genre_is_valid == 0) {
        fgets(intered_Genre, 30, stdin);
        remove_newline(intered_Genre);
        genre_is_valid = Allnamevalidation(intered_Genre);

        if (genre_is_valid == 1) {
            strcpy(b[book_num].Genre, intered_Genre);
        } else {
            printf("Your input includes invalid characters. Try again:\n");
        }
    }

    // Number of pages
    int page_success = 0;
    printf("Number of pages:\n");
    while (page_success == 0) {
        scanf("%d", &intered_Number_of_pages);
        clear_input_buffer();
        if (intered_Number_of_pages >= 1 && intered_Number_of_pages <= 10000000) {
            page_success = 1;
            b[book_num].Number_of_pages = intered_Number_of_pages;
        } else {
            printf("Your input is invalid. Try again:\n");
        }
    }

    // Year of publication
    int year_success = 0;
    printf("Year of publication:\n");
    while (year_success == 0) {
        scanf("%d", &intered_Year_of_publication);
        clear_input_buffer();
        if (intered_Year_of_publication >= 1 && intered_Year_of_publication <= 3000) {
            year_success = 1;
            b[book_num].Year_of_publication = intered_Year_of_publication;
        } else {
            printf("Your input is invalid. Try again:\n");
        }
    }

    // Success message
    printf("%s is saved in the system!\n", b[book_num].Name);
}

void part_3_menu() {
    printf("1-Search a book's status\n2-Search a person's borrowed books\n3-Borrow a book\n4-Return a book\n0-Return to main menu\n");

    int Function;
    scanf("%d", &Function);
    clear_input_buffer();

    switch (Function) {
        case 1:
            search_book_status();
            break;
        case 2:
            see_A_persons_borrowed_books();
            break;
        case 3:
            Add_a_borrow();
            break;
        case 4:
            ReturnBook();
            break;
        case 0:
            return;
        default:
            printf("Please enter a valid value.\n");
            break;
    }
}

int if_book_exist(char *str) {
    for (int i = 0; i < book_num; i++) {
        if (strcmp(b[i].Name, str) == 0)
            return i;
    }
    return -1;
}

int find_by_phone(char *str) {
    for (int i = 0; i < person_num; i++) {
        if (strcmp(p[i].PhoneNumber, str) == 0)
            return i;
    }
    return -1;
}

void Add_a_borrow() {
    char intererd_BookName[30];
    char intered_PhoneNumber[30];

    printf("Enter the name of the book:\n");
    fgets(intererd_BookName, 30, stdin);
    remove_newline(intererd_BookName);

    printf("Enter the phone number of the borrower:\n");
    fgets(intered_PhoneNumber, 30, stdin);
    remove_newline(intered_PhoneNumber);

    int book_index = if_book_exist(intererd_BookName);
    int person_index = find_by_phone(intered_PhoneNumber);

    if (book_index == -1) {
        printf("No such book exists!\n");
    } else if (b[book_index].is_borrowed == 1) {
        printf("The book has been already borrowed!\n");
    } else if (person_index == -1) {
        printf("No such person exists!\n");
    } else {
        borrow[borrow_num].borrowed_book = &b[book_index];
        borrow[borrow_num].borrower_person = &p[person_index];
        borrow[borrow_num].is_returned = 0;
        b[book_index].is_borrowed = 1;
        printf("\"%s\" borrowed \"%s\" successfully.\n", borrow[borrow_num].borrower_person, intererd_BookName);
        borrow_num++;
    }
}

void search_book_status() {
    char intererd_BookName[30];
    printf("Enter the name of the book:\n");
    fgets(intererd_BookName, 30, stdin);
    remove_newline(intererd_BookName);

    int book_index = if_book_exist(intererd_BookName);
    if (book_index != -1) {
        if (b[book_index].is_borrowed == 1) {
            printf("The book \"%s\" is borrowed.\n", intererd_BookName);
        } else {
            printf("The book \"%s\" is available.\n", intererd_BookName);
        }
    } else {
        printf("No such book exists!\n");
    }
}

void see_A_persons_borrowed_books() {
    char intered_PhoneNumber[30];
    printf("Enter the phone number of the person:\n");
    fgets(intered_PhoneNumber, 30, stdin);
    remove_newline(intered_PhoneNumber);

    int person_index = find_by_phone(intered_PhoneNumber);
    if (person_index == -1) {
        printf("No such person exists!\n");
        return;
    }

    int j = 1;
    int count_borrow_ongoing = 0;
    for (int i = 0; i < borrow_num; i++) {
        if (borrow[i].borrower_person == &p[person_index]) {
            printf("%d-%s\n", j, borrow[i].borrowed_book->Name);
            j++;
            if (borrow[i].is_returned == 0) {
                count_borrow_ongoing++;
            }
        }
    }
    printf("%d books are still in their hands!\n", count_borrow_ongoing);
}

void ReturnBook() {
    char intererd_BookName[30];
    char intered_PhoneNumber[30];

    printf("Enter the name of the book to return:\n");
    fgets(intererd_BookName, 30, stdin);
    remove_newline(intererd_BookName);

    printf("Enter the phone number of the borrower:\n");
    fgets(intered_PhoneNumber, 30, stdin);
    remove_newline(intered_PhoneNumber);

    int book_index = if_book_exist(intererd_BookName);
    int person_index = find_by_phone(intered_PhoneNumber);

    if (book_index == -1) {
        printf("No such book exists!\n");
    } else if (person_index == -1) {
        printf("No such person exists!\n");
    } else {
        // Find the borrow record
        int borrow_index = -1;
        for (int i = 0; i < borrow_num; i++) {
            if (borrow[i].borrowed_book == &b[book_index] && borrow[i].borrower_person == &p[person_index] && borrow[i].is_returned == 0) {
                borrow_index = i;
                break;
            }
        }

        if (borrow_index == -1) {
            printf("This book is not borrowed by this person!\n");
        } else {
            borrow[borrow_index].is_returned = 1;
            b[book_index].is_borrowed = 0;
            printf("\"%s\" returned \"%s\" successfully.\n", intered_PhoneNumber, intererd_BookName);
        }
    }
}

