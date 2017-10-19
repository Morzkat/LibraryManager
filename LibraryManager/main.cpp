#include <iostream>

using namespace std;

// strcut basic for a item
struct book
{
    short id;
    string titleBook;
    string author;
    string publisher;
    string publishedDate;
    string category;

    struct book* next;
};

// first and last item objects
book* books = NULL;

// class for action
class Stack
{
public:

    static void menu();
    static void createBook();
    static void push(book*);
    static book* pop();
    static void getLastBook();
    static void showBooks(book*);
    static void searchByCategory();

};

void Stack::searchByCategory()
{
    //show the items if there are
    if (books != NULL)
    {
        string categoryToSearch;
        cout << "Seleccione la categoria de que desea buscar: ";
        cin >> categoryToSearch;

        book* i = books;

        while(i != NULL)
        {
            if (i->category != categoryToSearch)
            { cout << i->titleBook << " no coincide con la busqueda " << endl; }

            else
            { cout << i->titleBook << " coincide con la busqueda " << endl; }

            i = i->next;
        }
    }

        //there aren't items
    else
    {
        cout << "La lista esta vacia\n";
    }
}

void Stack::createBook()
{
    string titleBook;
    string author;
    string publisher;
    string publishedDate;
    string category;

    //create a new struct for a item
    book* newBook = new (struct book);

    //get the data for the item
    cout << "Introduzca el titulo del libro:";
    cin >> titleBook;

    cout << "Introduzca el autor del libro:";
    cin >> author;

    cout << "Introduzca la editora del libro:";
    cin >> publisher;

    cout << "Introduzca el dia que fue publicado del libro:";
    cin >> publishedDate;

    cout << "Introduzca la categoria del libro:";
    cin >> category;

    //add the data to the book
    newBook->titleBook = titleBook;
    newBook->author = author;
    newBook->publisher = publisher;
    newBook->publishedDate = publishedDate;
    newBook->category = category;

    newBook->id = (books == NULL) ? 1 : books->id + 1;

    //add the item to the list of items
    push(newBook);

    cout << "Libro Agregado\n";
}

void Stack::getLastBook()
{
    //show the items if there are
    if (books != NULL)
    {
        book* nextBook = books->next;
        book* lastBook = books;

        cout << "titulo del libro: " << lastBook->titleBook << "\n" "autor: " << lastBook->author << "\n" "editora: " << lastBook->publisher
             << "\n" "dia de publicacion: " << lastBook->publishedDate << "\n" "categoria del libro: " << lastBook->category << "\n";
        cout << "-----------------------------------------------------------\n";

        books = nextBook;
        delete(lastBook);

    }
    //there aren't items
    else
    {
        cout << "La lista esta vacia\n";
    }

}

void Stack::push(book* newBook)
{
    //last item like null
    newBook->next = NULL;

    //doesn't exist first item
    if (books == NULL)
    {
        //the first and the last item are the same
        books = newBook;
    }

    //exist a first item
    else
    {
        //new book get all the others book and become the latest(the latest introduced)
        newBook->next = books;
        //all the books
        books = newBook;
    }
}

void Stack::showBooks(book* books)
{
    //show the items if there are
    if (books != NULL)
    {
        book* i = books;

        while(i != NULL)
        {
            cout << "titulo del libro: " << i->titleBook << "\n" "autor: " << i->author << "\n" "editora: " << i->publisher
                 << "\n" "dia de publicacion: " << i->publishedDate << "\n" "categoria del libro: " << i->category << "\n";
            cout << "-----------------------------------------------------------\n";
            i = i->next;
        }
    }

        //there aren't items
    else
    {
        cout << "La lista esta vacia\n";
    }
}

void Stack::menu()
{
    //menu for the options
    cout << "Elige una de las opciones\n";
    cout << "1- Listar libros\n";
    cout << "2- Introducir un libro\n";
    cout << "3- Solicitar ultimo libro de la pila \n";
    cout << "4- Buscar libro por categoria\n";
    cout << "5- Salir\n";
    cout << "Elija una opcion =>";
}

int main()
{

    // switch opcion
    short op;
    
    
    do
    {
        Stack::menu();

        cin >> op;

        switch (op)
        {
            case 1 : Stack::showBooks(books);
                break;

            case 2:
                Stack::createBook();
                break;

            case 3: Stack::getLastBook();
                break;

            case 4: Stack::searchByCategory();
                break;
        }
    }while (op < 5);
}