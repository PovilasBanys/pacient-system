#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const char file[] = "rez.txt";
const char file1[] = "duom.txt";
 ofstream oup;
 ifstream inp;

class list
{
public:
	struct node {
		string id;
		string amzius;
		string simptomai;
		string diagnoze;
		string name;
		string pavarde;
		string laikas;
		string lytis;
		struct node *next;
		int sk;
	}
	*head, *tail, *ptr;

	list(){
	    head = NULL;
	    tail = NULL;

       oup.open(file);
       inp.open(file1);


    }
	~list();

	struct list::node* searchName(struct list::node*, string);
	struct list::node* searchId(struct list::node*, string);
	struct list::node* searchLaikas(struct list::node*, string);
	struct list::node* searchPavarde(struct list::node*, string );
	struct list::node* initNode(string, string, string, string, string,string,string,string);
	struct list::node* initNodeFile(string, string, string, string, string,string,string,string);

	void addNode( struct list::node*);
	void insertNode( struct list::node*);
	void deleteNode( struct list::node*);

	void deleteList( struct list::node*);
	void displayList( struct list::node*)const;
 	void displayNode( struct list::node*) const;
 	void displayNodeDiagnoze( struct list::node*) const;


};

list::~list() {
	node *current,*temp;
	current = head;
	temp = head;
	while(current != NULL) {
		current = current->next;
		delete temp;
		temp = current;
	}
}

struct list::node* list::initNode(string n, string i, string a, string p, string l,string laik,string simp, string diag ) {
	struct node *ptr = new node;

cout<<"Iveskite paciento varda: "<<endl;
cin>>n;
cout<<"Iveskite paciento pavarde : "<<endl;
cin>>p;
cout<<"Iveskite paciento asmens koda: "<<endl;
cin>>i;
cout<<"Iveskite paciento lyti: "<<endl;
cin>>l;
cout<<"Iveskite paciento amziu: "<<endl;
cin>>a;
cout<<"Iveskite priemimo priemimo laika: "<<endl;
cin>>laik;
cout<<"Iveskite paciento simptomus"<<endl;
cin>>simp;
cout<<"Iveskite paciento diagnoze"<<endl;
cin>>diag;


	if( ptr == NULL )
		return 0;

	else {
		ptr->name = n ;
		ptr->pavarde = p;
		ptr->id = i ;
		ptr->lytis = l;
		ptr->amzius = a;
		ptr->laikas= laik;
		ptr->simptomai= simp;
		ptr->diagnoze= diag;
		return ptr;
	}
}

struct list::node* list::initNodeFile(string n, string i, string a, string p, string l,string laik,string simp, string diag) {
	struct node *ptr = new node;



//while(!inp.eof()){
while(!inp.eof()){
        inp>> n;
        inp>> p;
        inp>> i;
        inp>> l;
        inp>> a;
        inp>> laik;
        inp>> simp;
        inp>> diag;


		ptr->name = n ;
		ptr->pavarde = p;
		ptr->id = i ;
		ptr->lytis = l;
		ptr->amzius = a;
		ptr->laikas= laik;
		ptr->simptomai= simp;
		ptr->diagnoze= diag;
		return ptr;
	}
}

void list::addNode( struct node *newNode )  {

	if( head == NULL ) {
		head = newNode;
		tail = newNode;
	}

	tail->next = newNode;
	newNode->next = NULL;
	tail = newNode;
}


struct list::node* list::searchName(struct node* ptr, string name) {
    while( name != ptr->name ) {
       ptr = ptr->next;
       if( ptr == NULL )
          break;
    }
    return ptr;
}

struct list::node* list::searchId(struct node* ptr, string id) {
    while( id != ptr->id ) {
       ptr = ptr->next;
       if( ptr == NULL )
          break;
    }
    return ptr;
}

struct list::node* list::searchLaikas(struct node* ptr, string laikas) {
    while( laikas != ptr->laikas ) {
       ptr = ptr->next;
       if( ptr == NULL )
          break;
    }
    return ptr;
}

struct list::node* list::searchPavarde(struct node* ptr, string pavarde) {
    while( pavarde != ptr->pavarde) {
       ptr = ptr->next;
       if( ptr == NULL )
          break;
    }
    return ptr;
}

void list::deleteNode( struct list::node *ptr)
{

  struct node *temp, *prev;
   temp = ptr;
   prev = head;

   if( temp == prev ) {
       head = head->next;
       if( tail == temp )
          tail = tail->next;
          oup << temp->name <<"  "<< temp->pavarde<<"  "<<temp->id<<"  "<<temp->lytis<<"  "<<temp->amzius<<"  "<<temp->laikas<<"  "<<temp->simptomai<<"  "<<temp->diagnoze<< endl;
       delete temp ;

   }
   else {
       while( prev->next != temp ) {
           prev = prev->next;
       }
       prev->next = temp->next;
       if( tail == temp )
           tail = prev;
           oup << temp->name <<"  "<< temp->pavarde<<"  "<<temp->id<<"  "<<temp->lytis<<"  "<<temp->amzius<<"  "<<temp->laikas<<"  "<<temp->simptomai<<"  "<<temp->diagnoze<< endl;
      delete temp;
   }
}

void list::deleteList( struct node *ptr )
{
   struct node *temp;

   if( head == NULL ) return;

   if( ptr == head ) {
       head = NULL;
       tail = NULL;
   }
   else {
       temp = head;
       while( temp->next != ptr )
           temp = temp->next;
       tail = temp;
   }

   while( ptr != NULL ) {
      temp = ptr->next;
      oup << ptr->name <<"  "<< ptr->pavarde<<"  "<<ptr->id<<"  "<<ptr->lytis<<"  "<<ptr->amzius<<"  "<<ptr->laikas<<"  "<<ptr->simptomai<<"  "<<ptr->diagnoze<< endl;
      delete ptr;

      ptr = temp;
   }

}
void list::displayNode( struct list::node *ptr ) const
{
	cout<< ptr->name <<"  "<< ptr->pavarde<<"  "<<ptr->id<<"  "<<ptr->lytis<<"  "<<ptr->amzius<<"  "<<ptr->laikas<<"  "<<ptr->simptomai<<"  "<<ptr->diagnoze<< endl;
}

void list::displayNodeDiagnoze( struct list::node *ptr ) const
{
    string diagnoze1;
    string name1;
    cout<<"Parasykite nauja diagnoze: "<<endl;
    cin>>diagnoze1;
    ptr->diagnoze=diagnoze1;
	cout << ptr->name <<"  "<< ptr->pavarde<<"  "<<ptr->id <<"  "<<ptr->lytis<<"  "<<ptr->amzius<<"  "<<ptr->laikas<<"  "<<ptr->simptomai<<"  "<<ptr->diagnoze<< endl;
}

void list::displayList( struct list::node *ptr ) const
{
	if(!ptr) cout << "Nothing to display" << endl;
	while(ptr) {
		displayNode(ptr);
		ptr = ptr->next;

	}
}

int main(int argc, char *argv[])
{
	    string id;
		string amzius;
		string simptomai;
		string diagnoze;
		string name;
		string pavarde;
		string laikas;
		string lytis, name1;
		int sk;
 	list myList;
	list::node* ptr;
    bool loop = true;
    int skaicius;

    while(loop){

      cout<<endl;
      cout<<"Meniu"<<endl;
      cout<<endl;
      cout<<" Pasirinkite norima veiksma: "<<endl;
      cout<<"1 - Prideti pacienta i sarasa is failo "<<endl;
      cout<<"2 - Prideti pacienta i sarasa is konsoles "<<endl;
      cout<<"3 - Parodyti pacientu sarasa "<<endl;
      cout<<"4 - Istrinti pacienta is saraso "<< endl;
      cout<<"5 - ieskoti pagal paciento varda ir pavarde "<<endl;
      cout<<"6 - ieskoti pagal paciento asmens koda "<<endl;
      cout<<"7 - ieskoti pagal paciento priemimo laika "<<endl;
      cout<<"8 - Pakeisti paciento diagnoze "<<endl;
      cout<<"9 - Istrinti visa sarasa"<< endl;
      cout<<"10 - Iseiti"<<endl;


      cin>>skaicius;

      switch(skaicius){

           case 1:
         ptr = myList.initNodeFile( name, id, amzius,  pavarde, lytis, laikas, simptomai, diagnoze);
	myList.addNode(ptr);
          break;

        case 2:
         ptr = myList.initNode( name, id, amzius,  pavarde, lytis, laikas, simptomai, diagnoze);
	myList.addNode(ptr);
          break;
        case 3:
            cout<<"Pacientu sarasas:"<<endl;
          myList.displayList(myList.head);
          break;
        case 4:
          cout<<"parasykite istrinamo paciento asmens koda"<<endl;
    cin>>id;
	ptr = myList.searchId( myList.head, id );
	if( ptr == NULL ) {
		cout << "Asmens kodas: " << id << " nerastas" << endl;
	}
	else {
		cout << "Pacientas istrintas.  ";
		myList.deleteNode( ptr);
	}
          break;
        case 5:
    cout<<"parasykite ieskoma varda: "<<endl;
    cin>>name;
    ptr = myList.searchName( myList.head,name);
    if(ptr != NULL){
    cout<<"parasykite ieskoma pavarde: "<<endl;
    cin>>pavarde;
	ptr = myList.searchPavarde( myList.head,pavarde);
	if( ptr != NULL ) {
		cout << "Pacientas: "<< endl;
		myList.displayNode(ptr);
	}
    }
    if(ptr == NULL){
        cout<<"Tokio paciento nera!"<<endl;
    }
          break;

        case 6:
          cout<<"Iveskite id"<<endl;
          cin>>id;
	ptr = myList.searchId( myList.head,id );
	if( ptr == NULL ) {
		cout << "Pacientas su asmens kodu " << id << " nerastas" << endl;
	}
	else {
		cout << "pacientas pagal ieskoma asmens koda:  ";
	    myList.displayNode(ptr);
	}
	break;

	case 7:
          cout<<"Iveskite priemimo laika "<<endl;
          cin>>laikas;
	ptr = myList.searchLaikas( myList.head,laikas );
	if( ptr == NULL ) {
		cout << "Pacientas su priemimo laiku " << laikas << " nerastas" << endl;
	}
	else {
		cout << "pacientas pagal ieskoma priemimo laika:  ";
	    myList.displayNode(ptr);
	}
          break;
        case 8:
            cout<<"Iveskite asmens koda"<<endl;
          cin>>id;
	ptr = myList.searchId( myList.head, id );
	if( ptr == NULL ) {
		cout << "amens kodas: " << id << " nerastas" << endl;
	}
	else {
	    myList.displayNodeDiagnoze(ptr);
	}
          break;
        case 9:
          myList.deleteList(myList.head);
	myList.displayList(myList.head);
          break;
        case 10:
          loop = false;
          break;

        default:
          cout<<"Ivestas neteisingas skaicius"<<endl;
          break;
      }
    }

return 0;
}
