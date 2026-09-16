/*
 ============================================================
  PROJECT        : TWEET MANAGER SYSTEM
  (BCA - 1st YEAR 2nd SEMESTER)
  INSTITUTION    : DEZYNE �-COLE COLLEGE
  DATA STRUCTURE : SINGLY AND DOUBLY LINKED LIST
  Author         : Pradeep Jatav & Gopal Prajapat
  DATE           : 16-05-2026
  LOGIC          : DYNAMIC MEMORY MANAGEMENT(SLL & DLL)
  DESCRIPTION    : A menu-driven C++ program that manages
                   tweets using both Singly and Doubly
                   Linked Lists. Each tweet stores:
                     - Tweet ID (auto-generated)
                     - Username
                     - Tweet content
 ============================================================
*/

#include<iostream>
#include<conio.h>
#include<string>
using namespace std;

   // ============================================================
   //  SECTION 1 : SINGLY LINKED LIST
   // ============================================================

/*
  NODE class for Singly Linked List.
  Each node holds tweet data and a pointer to the NEXT node only.
*/
class NODE
{
public:
    string ID;      // Tweet ID  e.g. "TWEET1001"
    string UNAME;   // Username
    string TWEET;   // Tweet content
    NODE  *NEXT;    // Pointer to next node

    NODE(string x, string y, string z)
    {
        ID    = x;
        UNAME = y;
        TWEET = z;
        NEXT  = nullptr;
    }
};

   /*
     LinkList class implements all Singly Linked List operations:
      - Insert at Beginning / End / Given Position
      - Delete from Beginning / End / Given Position
      - Traversal (display all tweets)
      - Search tweets by username
      - Count total nodes
   */
class LinkList
{
public:
    string TID;
    int    TCNT;
    string UName, UTweet;
    NODE  *START, *END;
    int    countNode;

    // Constructor � initialises an empty list
    LinkList()
    {
        TCNT      = 1001;
        countNode = 0;
        START     = nullptr;
        END       = nullptr;
    }

    // --------------------------------------------------------
    //  Input helper � reads username and tweet from user
    // --------------------------------------------------------
    void getData()
    {
        TID = "TWEET" + to_string(TCNT);
        cout << "\nAuto-generated TID -- " << TID << endl;
        cout << "Enter User Name  -- ";
        getline(cin, UName);
        cout << "Enter Tweet      -- ";
        getline(cin, UTweet);
    }

    // --------------------------------------------------------
    //  Continue-check menu shown after every operation
    // --------------------------------------------------------
    char continueCheck()
    {
        char c;
        cout << "\n\nWhat would you like to do?\n";
        cout << "1. Continue with Same Operation\n";
        cout << "2. Go to Previous Menu\n";
        cout << "3. Go to Main Menu\n";
        cout << "4. Exit\n";
        c = getch();
        if (c == '4')
        {
            thanksLine();
            exit(0);
        }
        return c;
    }

    /*
       --------------------------------------------------------
        INSERT NODE
        opr = 1 : At Beginning
        opr = 2 : At End
        opr = 3 : At Given Position
       --------------------------------------------------------
    */
    int insertNode(int opr)
    {
        system("cls");

        if (opr == 1)
        {
            cout << "\n\n--- Insert At Beginning ---\n\n";
            getData();
            NODE *TEMP = new NODE(TID, UName, UTweet);
            if (TEMP == nullptr)
            {
                cout << "Insufficient Memory!\n";
                return 0;
            }
            if (START == nullptr)
                END = START = TEMP;
            else
            {
                TEMP->NEXT = START;
                START = TEMP;
            }
            countNode++;
            TCNT++;
            cout << "\nTweet inserted at beginning successfully!\n";
        }
        else if (opr == 2)
        {
            cout << "\n\n--- Insert At End ---\n\n";
            getData();
            NODE *TEMP = new NODE(TID, UName, UTweet);
            if (TEMP == nullptr)
            {
                cout << "Insufficient Memory!\n";
                return 0;
            }
            if (START == nullptr)
                END = START = TEMP;
            else
            {
                END->NEXT = TEMP;
                END = TEMP;
            }
            countNode++;
            TCNT++;
            cout << "\nTweet inserted at end successfully!\n";
        }
        else if (opr == 3)
        {
            cout << "\n\n--- Insert At Given Position ---\n\n";
            cout << "Total existing nodes: " << countNode << "\n\n";
            int pos;
            getData();
            cout << "Enter Position (1 to " << countNode + 1 << ") -- ";
            cin >> pos;
            cin.ignore();

            if (pos < 1 || pos > countNode + 1)
            {
                cout << "Invalid position!\n";
                return 0;
            }

            NODE *TEMP = new NODE(TID, UName, UTweet);
            if (TEMP == nullptr)
            {
                cout << "Insufficient Memory!\n";
                return 0;
            }

            if (START == nullptr || pos == 1)
            {
                TEMP->NEXT = START;
                START = TEMP;
                if (END == nullptr) END = TEMP;
            }
            else
            {
                NODE *TEMP1 = START;
                for (int i = 2; i < pos; i++)
                    TEMP1 = TEMP1->NEXT;

                TEMP->NEXT = TEMP1->NEXT;
                TEMP1->NEXT = TEMP;
                if (TEMP1 == END)
                    END = TEMP;
            }
            countNode++;
            TCNT++;
            cout << "\nTweet inserted at position " << pos << " successfully!\n";
        }

        char c = continueCheck();
        if      (c == '1') insertNode(opr);
        else if (c == '2') insertionOperation();
        else if (c == '3') MainMenu();
        return 0;
    }

    // --------------------------------------------------------
    //  DISPLAY / TRAVERSE all tweets
    // --------------------------------------------------------
    void showNode()
    {
        system("cls");
        cout << "\n\n--- Singly Linked List Traversal ---\n\n";
        if (START == nullptr)
        {
            cout << "HEAD --> NULL\n\nList is empty!\n";
            return;
        }
        cout << "HEAD --> ";
        NODE *TEMP = START;
        while (TEMP != nullptr)
        {
            cout << "[" << TEMP->ID << " | "
                 << TEMP->UNAME   << " | "
                 << TEMP->TWEET   << "] --> ";
            TEMP = TEMP->NEXT;
        }
        cout << "NULL\n";
        cout << "\nTotal tweets: " << countNode << "\n";
    }

    // --------------------------------------------------------
    //  COUNT NODES
    // --------------------------------------------------------
    void countNodes()
    {
        system("cls");
        cout << "--- Count Nodes ---\n\n";
        cout << "Total number of tweets: " << countNode << "\n";
    }

    // --------------------------------------------------------
    //  INSERTION OPERATION SUB-MENU
    // --------------------------------------------------------
    int insertionOperation()
    {
        system("cls");
        cout << "\n--- Insertion Operation (Singly) ---\n\n";
        cout << "1. Insert At Beginning\n";
        cout << "2. Insert At End\n";
        cout << "3. Insert At Given Position\n";
        cout << "4. Go to Main Menu\n";
        cout << "5. Exit\n";
        char c = getch();
        if      (c == '1') insertNode(1);
        else if (c == '2') insertNode(2);
        else if (c == '3') insertNode(3);
        else if (c == '4') MainMenu();
        else if (c == '5') { thanksLine(); exit(0); }
        return 0;
    }

    /*
       --------------------------------------------------------
        DELETE NODE
        opr = 1 : From Beginning
        opr = 2 : From End
        opr = 3 : From Given Position
       --------------------------------------------------------
    */
    int deleteNode(int opr)
    {
        system("cls");
        NODE *TEMP;

        if (opr == 1)
        {
            cout << "\n\n--- Delete From Beginning ---\n\n";
            if (START == nullptr)
            {
                cout << "List is Empty!\n";
                return 0;
            }
            else if (START->NEXT == nullptr)
            {
                TEMP  = START;
                END   = START = nullptr;
            }
            else
            {
                TEMP  = START;
                START = START->NEXT;
            }
            countNode--;
            cout << "Deleted tweet: [" << TEMP->ID << " | " << TEMP->UNAME << "]\n";
            delete TEMP;
            cout << "\nNode deleted successfully!\n";
        }
        else if (opr == 2)
        {
            /*
              NOTE FOR STUDENTS:
              In Singly LL, deleting from end requires O(n) traversal
              because we have no PREV pointer. We must scan from
              START until we reach the node just before END.
            */
            cout << "\n\n--- Delete From End ---\n\n";
            if (START == nullptr)
            {
                cout << "List is Empty!\n";
                return 0;
            }
            else if (START->NEXT == nullptr)
            {
                TEMP  = START;
                END   = START = nullptr;
            }
            else
            {
                TEMP = START;
                while (TEMP->NEXT != END)   // traverse to second-last
                    TEMP = TEMP->NEXT;

                NODE *T1   = END;
                TEMP->NEXT = nullptr;
                END        = TEMP;
                cout << "Deleted tweet: [" << T1->ID << " | " << T1->UNAME << "]\n";
                delete T1;
            }
            countNode--;
            cout << "\nNode deleted successfully!\n";
        }
        else if (opr == 3)
        {
            cout << "\n\n--- Delete From Given Position ---\n\n";
            if (START == nullptr)
            {
                cout << "List is Empty!\n";
                return 0;
            }
            int pos;
            cout << "Enter position to delete (1 to " << countNode << ") -- ";
            cin >> pos;
            cin.ignore();

            if (pos < 1 || pos > countNode)
            {
                cout << "Invalid position!\n";
                return 0;
            }

            if (pos == 1 && START == END)
            {
                TEMP  = START;
                START = END = nullptr;
            }
            else if (pos == 1)
            {
                TEMP  = START;
                START = START->NEXT;
            }
            else
            {
                TEMP = START;
                for (int i = 2; i < pos; i++)
                    TEMP = TEMP->NEXT;

                NODE *T1 = TEMP->NEXT;
                if (T1 == END)
                {
                    TEMP->NEXT = nullptr;
                    END        = TEMP;
                }
                else
                {
                    TEMP->NEXT = T1->NEXT;
                }
                cout << "Deleted tweet: [" << T1->ID << " | " << T1->UNAME << "]\n";
                delete T1;
                countNode--;
                cout << "\nNode deleted successfully!\n";

                char c = continueCheck();
                if      (c == '1') deleteNode(opr);
                else if (c == '2') deleteOperation();
                else if (c == '3') MainMenu();
                return 0;
            }
            cout << "Deleted tweet: [" << TEMP->ID << " | " << TEMP->UNAME << "]\n";
            delete TEMP;
            countNode--;
            cout << "\nNode deleted successfully!\n";
        }

        char c = continueCheck();
        if      (c == '1') deleteNode(opr);
        else if (c == '2') deleteOperation();
        else if (c == '3') MainMenu();
        return 0;
    }

    // --------------------------------------------------------
    //  DELETION OPERATION SUB-MENU
    // --------------------------------------------------------
    int deleteOperation()
    {
        system("cls");
        cout << "\n--- Deletion Operation (Singly) ---\n\n";
        cout << "1. Delete From Beginning\n";
        cout << "2. Delete From End\n";
        cout << "3. Delete From Given Position\n";
        cout << "4. Go to Main Menu\n";
        cout << "5. Exit\n";
        char c = getch();
        if      (c == '1') deleteNode(1);
        else if (c == '2') deleteNode(2);
        else if (c == '3') deleteNode(3);
        else if (c == '4') MainMenu();
        else if (c == '5') { thanksLine(); exit(0); }
        return 0;
    }

    // --------------------------------------------------------
    //  SEARCH � find all tweets by a given username
    // --------------------------------------------------------
    int searchTweetInNode()
    {
        system("cls");
        cout << "\n--- Search Tweet by Username (Singly) ---\n\n";
        if (START == nullptr)
        {
            cout << "List is empty!\n";
            return 0;
        }
        cout << "Enter Username to search -- ";
        string uname;
        getline(cin, uname);

        NODE *TEMP  = START;
        int counter = 0;
        while (TEMP != nullptr)
        {
            if (TEMP->UNAME == uname)
            {
                cout << "\n[" << TEMP->ID    << " | "
                              << TEMP->UNAME << " | "
                              << TEMP->TWEET << "]\n";
                counter++;
            }
            TEMP = TEMP->NEXT;
        }
        if (counter == 0)
            cout << "\nNo tweets found for user \"" << uname << "\".\n";
        else
            cout << "\nTotal tweets found: " << counter << "\n";

        char c;
        cout << "\n1. Search Again\n2. Go to Main Menu\n3. Exit\n";
        c = getch();
        if      (c == '1') searchTweetInNode();
        else if (c == '2') MainMenu();
        else if (c == '3') { thanksLine(); exit(0); }
        return 0;
    }

    // --------------------------------------------------------
    //  MAIN MENU � Singly Linked List
    // --------------------------------------------------------
    int MainMenu()
    {
        system("cls");
        cout << "========================================\n";
        cout << "   TWEET MANAGER - Singly Linked List  \n";
        cout << "========================================\n\n";
        cout << "Total Tweets : " << countNode << "\n\n";
        cout << "1. Insertion Operation\n";
        cout << "2. Traversal (Show All Tweets)\n";
        cout << "3. Deletion Operation\n";
        cout << "4. Search Tweet by Username\n";
        cout << "5. Count Nodes\n";
        cout << "6. Exit\n\n";
        cout << "Choose an option -- ";
        char c = getch();
        if      (c == '1') insertionOperation();
        else if (c == '2') { showNode(); cout << "\n\nPress any key to continue..."; getch(); MainMenu(); }
        else if (c == '3') deleteOperation();
        else if (c == '4') searchTweetInNode();
        else if (c == '5') { countNodes(); cout << "\nPress any key..."; getch(); MainMenu(); }
        else if (c == '6') { thanksLine(); exit(0); }
        return 0;
    }

    void thanksLine()
    {
        cout << "\n\nThank you for using Tweet Manager!\n\n";
    }
};


   // ============================================================
   //  SECTION 2 : DOUBLY LINKED LIST
   // ============================================================

   /*
     NODED class for Doubly Linked List.
     Each node holds tweet data and TWO pointers:
     PREV -- points to the previous node
     NEXT -- points to the next node
     This allows BOTH forward and backward traversal.
   */
class NODED
{
public:
    NODED  *PREV;   // Pointer to previous node
    string  ID;
    string  UNAME;
    string  TWEET;
    NODED  *NEXT;   // Pointer to next node

    NODED(string x, string y, string z)
    {
        PREV  = nullptr;
        ID    = x;
        UNAME = y;
        TWEET = z;
        NEXT  = nullptr;
    }
};

   /*
     DLinkList class implements all Doubly Linked List operations:
      - Insert at Beginning / End / Given Position
      - Delete from Beginning / End / Given Position
      - Forward and Backward Traversal
      - Search tweets by username
      - Count total nodes
   */
class DLinkList
{
public:
    string TID;
    int    TCNT;
    string UName, UTweet;
    NODED *START, *END;
    int    countNode;

    // Constructor � initialises an empty doubly linked list
    DLinkList()
    {
        TCNT      = 2001;   // separate ID range from singly list
        countNode = 0;
        START     = nullptr;
        END       = nullptr;
    }

    // --------------------------------------------------------
    //  Input helper
    // --------------------------------------------------------
    void getData()
    {
        TID = "TWEET" + to_string(TCNT);
        cout << "\nAuto-generated TID -- " << TID << endl;
        cout << "Enter User Name  -- ";
        getline(cin, UName);
        cout << "Enter Tweet      -- ";
        getline(cin, UTweet);
    }

    // --------------------------------------------------------
    //  Continue-check menu
    // --------------------------------------------------------
    char continueCheck()
    {
        char c;
        cout << "\n\nWhat would you like to do?\n";
        cout << "1. Continue with Same Operation\n";
        cout << "2. Go to Previous Menu\n";
        cout << "3. Go to Main Menu\n";
        cout << "4. Exit\n";
        c = getch();
        if (c == '4') { thanksLine(); exit(0); }
        return c;
    }

    /*
       --------------------------------------------------------
        INSERT NODE
        opr = 1 : At Beginning
        opr = 2 : At End
        opr = 3 : At Given Position
       --------------------------------------------------------
    */
    int insertNode(int opr)
    {
        system("cls");

        if (opr == 1)
        {
            cout << "\n\n--- Insert At Beginning (Doubly) ---\n\n";
            getData();
            NODED *TEMP = new NODED(TID, UName, UTweet);
            if (TEMP == nullptr) { cout << "Insufficient Memory!\n"; return 0; }

            if (START == nullptr)
                END = START = TEMP;
            else
            {
                TEMP->NEXT  = START;
                START->PREV = TEMP;   // key step: set old HEAD's PREV
                START       = TEMP;
            }
            countNode++;
            TCNT++;
            cout << "\nTweet inserted at beginning successfully!\n";
        }
        else if (opr == 2)
        {
            cout << "\n\n--- Insert At End (Doubly) ---\n\n";
            getData();
            NODED *TEMP = new NODED(TID, UName, UTweet);
            if (TEMP == nullptr) { cout << "Insufficient Memory!\n"; return 0; }

            if (START == nullptr)
                END = START = TEMP;
            else
            {
                END->NEXT  = TEMP;
                TEMP->PREV = END;     // key step: new node's PREV = old END
                END        = TEMP;
            }
            countNode++;
            TCNT++;
            cout << "\nTweet inserted at end successfully!\n";
        }
        else if (opr == 3)
        {
            cout << "\n\n--- Insert At Given Position (Doubly) ---\n\n";
            cout << "Total existing nodes: " << countNode << "\n\n";
            int pos;
            getData();
            cout << "Enter Position (1 to " << countNode + 1 << ") -- ";
            cin >> pos;
            cin.ignore();

            if (pos < 1 || pos > countNode + 1)
            {
                cout << "Invalid position!\n";
                return 0;
            }

            NODED *TEMP = new NODED(TID, UName, UTweet);
            if (TEMP == nullptr) { cout << "Insufficient Memory!\n"; return 0; }

            if (START == nullptr || pos == 1)
            {
                TEMP->NEXT = START;
                if (START) START->PREV = TEMP;
                START = TEMP;
                if (END == nullptr) END = TEMP;
            }
            else
            {
                NODED *TEMP1 = START;
                for (int i = 2; i < pos; i++)
                    TEMP1 = TEMP1->NEXT;

                // Stitch PREV and NEXT pointers for all affected nodes
                TEMP->NEXT  = TEMP1->NEXT;
                TEMP->PREV  = TEMP1;
                TEMP1->NEXT = TEMP;
                if (TEMP->NEXT != nullptr)
                    TEMP->NEXT->PREV = TEMP;
                else
                    END = TEMP;
            }
            countNode++;
            TCNT++;
            cout << "\nTweet inserted at position " << pos << " successfully!\n";
        }

        char c = continueCheck();
        if      (c == '1') insertNode(opr);
        else if (c == '2') insertionOperation();
        else if (c == '3') MainMenu();
        return 0;
    }

    /*
       --------------------------------------------------------
        DISPLAY / TRAVERSE
        dir = 1 : Forward  (HEAD --> ... --> null)
        dir = 2 : Backward (TAIL --> ... --> null)
       --------------------------------------------------------
    */
    int showNode()
    {
        system("cls");
        cout << "\n\n--- Doubly Linked List Traversal ---\n\n";
        if (START == nullptr)
        {
            cout << "HEAD <--> NULL\n\nList is empty!\n";
            return 0;
        }
        cout << "1. Forward Traversal  (HEAD to TAIL)\n";
        cout << "2. Backward Traversal (TAIL to HEAD)\n";
        cout << "3. Go to Main Menu\n";
        cout << "4. Exit\n";
        char c = getch();

        if (c == '1')
        {
            cout << "\n\n--- Forward Traversal ---\n\n";
            cout << "NULL <-- ";
            NODED *TEMP = START;
            while (TEMP != nullptr)
            {
                cout << "[" << TEMP->ID    << " | "
                            << TEMP->UNAME << " | "
                            << TEMP->TWEET << "] <--> ";
                TEMP = TEMP->NEXT;
            }
            cout << "NULL\n";
        }
        else if (c == '2')
        {
            /*
              BACKWARD TRAVERSAL � only possible in Doubly LL
              because each node stores a PREV pointer.
              In Singly LL this would be impossible without
              reversing the list first.
            */
            cout << "\n\n--- Backward Traversal ---\n\n";
            cout << "NULL <-- ";
            NODED *TEMP = END;
            while (TEMP != nullptr)
            {
                cout << "[" << TEMP->ID    << " | "
                            << TEMP->UNAME << " | "
                            << TEMP->TWEET << "] <--> ";
                TEMP = TEMP->PREV;
            }
            cout << "NULL\n";
        }
        else if (c == '3') MainMenu();
        else if (c == '4') { thanksLine(); exit(0); }
        return 0;
    }

    // --------------------------------------------------------
    //  COUNT NODES
    // --------------------------------------------------------
    void countNodes()
    {
        system("cls");
        cout << "--- Count Nodes ---\n\n";
        cout << "Total number of tweets: " << countNode << "\n";
    }

    // --------------------------------------------------------
    //  INSERTION OPERATION SUB-MENU
    // --------------------------------------------------------
    int insertionOperation()
    {
        system("cls");
        cout << "\n--- Insertion Operation (Doubly) ---\n\n";
        cout << "1. Insert At Beginning\n";
        cout << "2. Insert At End\n";
        cout << "3. Insert At Given Position\n";
        cout << "4. Go to Main Menu\n";
        cout << "5. Exit\n";
        char c = getch();
        if      (c == '1') insertNode(1);
        else if (c == '2') insertNode(2);
        else if (c == '3') insertNode(3);
        else if (c == '4') MainMenu();
        else if (c == '5') { thanksLine(); exit(0); }
        return 0;
    }

    /*
       --------------------------------------------------------
        DELETE NODE
        opr = 1 : From Beginning
        opr = 2 : From End
        opr = 3 : From Given Position
       --------------------------------------------------------
    */
    int deleteNode(int opr)
    {
        system("cls");
        NODED *TEMP;

        if (opr == 1)
        {
            cout << "\n\n--- Delete From Beginning (Doubly) ---\n\n";
            if (START == nullptr) { cout << "List is Empty!\n"; return 0; }

            if (START->NEXT == nullptr)
            {
                TEMP  = START;
                END   = START = nullptr;
            }
            else
            {
                TEMP        = START;
                START       = START->NEXT;
                START->PREV = nullptr;    // key step: new HEAD's PREV = null
            }
            cout << "Deleted: [" << TEMP->ID << " | " << TEMP->UNAME << "]\n";
            delete TEMP;
            countNode--;
            cout << "\nNode deleted successfully!\n";
        }
        else if (opr == 2)
        {
            /*
              NOTE FOR STUDENTS:
              Deleting from end in Doubly LL is O(1)!
              We directly access END->PREV � no scanning needed.
              Compare this to Singly LL where we had to loop
              through the whole list with while(TEMP->NEXT != END).
            */
            cout << "\n\n--- Delete From End (Doubly) ---\n\n";
            if (START == nullptr) { cout << "List is Empty!\n"; return 0; }

            if (START->NEXT == nullptr)
            {
                TEMP  = START;
                END   = START = nullptr;
            }
            else
            {
                TEMP      = END;
                END       = END->PREV;   // O(1) � direct PREV access
                END->NEXT = nullptr;
            }
            cout << "Deleted: [" << TEMP->ID << " | " << TEMP->UNAME << "]\n";
            delete TEMP;
            countNode--;
            cout << "\nNode deleted successfully! [O(1) using PREV pointer]\n";
        }
        else if (opr == 3)
        {
            cout << "\n\n--- Delete From Given Position (Doubly) ---\n\n";
            if (START == nullptr) { cout << "List is Empty!\n"; return 0; }

            int pos;
            cout << "Enter position to delete (1 to " << countNode << ") -- ";
            cin >> pos;
            cin.ignore();

            if (pos < 1 || pos > countNode)
            {
                cout << "Invalid position!\n";
                return 0;
            }

            if (pos == 1 && START == END)
            {
                TEMP  = START;
                START = END = nullptr;
            }
            else
            {
                TEMP = START;
                for (int i = 1; i < pos; i++)
                    TEMP = TEMP->NEXT;

                if (TEMP == END)
                {
                    TEMP->PREV->NEXT = nullptr;
                    END              = TEMP->PREV;
                }
                else
                {
                    // Update both PREV and NEXT of neighbours
                    TEMP->PREV->NEXT = TEMP->NEXT;
                    TEMP->NEXT->PREV = TEMP->PREV;
                }
            }
            cout << "Deleted: [" << TEMP->ID << " | " << TEMP->UNAME << "]\n";
            delete TEMP;
            countNode--;
            cout << "\nNode deleted successfully!\n";
        }

        char c = continueCheck();
        if      (c == '1') deleteNode(opr);
        else if (c == '2') deleteOperation();
        else if (c == '3') MainMenu();
        return 0;
    }

    // --------------------------------------------------------
    //  DELETION OPERATION SUB-MENU
    // --------------------------------------------------------
    int deleteOperation()
    {
        system("cls");
        cout << "\n--- Deletion Operation (Doubly) ---\n\n";
        cout << "1. Delete From Beginning\n";
        cout << "2. Delete From End\n";
        cout << "3. Delete From Given Position\n";
        cout << "4. Go to Main Menu\n";
        cout << "5. Exit\n";
        char c = getch();
        if      (c == '1') deleteNode(1);
        else if (c == '2') deleteNode(2);
        else if (c == '3') deleteNode(3);
        else if (c == '4') MainMenu();
        else if (c == '5') { thanksLine(); exit(0); }
        return 0;
    }

    // --------------------------------------------------------
    //  SEARCH � find all tweets by a given username
    // --------------------------------------------------------
    int searchTweetInNode()
    {
        system("cls");
        cout << "\n--- Search Tweet by Username (Doubly) ---\n\n";
        if (START == nullptr) { cout << "List is empty!\n"; return 0; }

        cout << "Enter Username to search -- ";
        string uname;
        getline(cin, uname);

        NODED *TEMP = START;
        int counter = 0;
        while (TEMP != nullptr)
        {
            if (TEMP->UNAME == uname)
            {
                cout << "\n[" << TEMP->ID    << " | "
                              << TEMP->UNAME << " | "
                              << TEMP->TWEET << "]\n";
                counter++;
            }
            TEMP = TEMP->NEXT;
        }
        if (counter == 0)
            cout << "\nNo tweets found for user \"" << uname << "\".\n";
        else
            cout << "\nTotal tweets found: " << counter << "\n";

        char c;
        cout << "\n1. Search Again\n2. Go to Main Menu\n3. Exit\n";
        c = getch();
        if      (c == '1') searchTweetInNode();
        else if (c == '2') MainMenu();
        else if (c == '3') { thanksLine(); exit(0); }
        return 0;
    }

    // --------------------------------------------------------
    //  MAIN MENU � Doubly Linked List
    // --------------------------------------------------------
    int MainMenu()
    {
        system("cls");
        cout << "========================================\n";
        cout << "   TWEET MANAGER - Doubly Linked List  \n";
        cout << "========================================\n\n";
        cout << "Total Tweets : " << countNode << "\n\n";
        cout << "1. Insertion Operation\n";
        cout << "2. Traversal (Forward / Backward)\n";
        cout << "3. Deletion Operation\n";
        cout << "4. Search Tweet by Username\n";
        cout << "5. Count Nodes\n";
        cout << "6. Exit\n\n";
        cout << "Choose an option -- ";
        char c = getch();
        if      (c == '1') insertionOperation();
        else if (c == '2') { showNode(); cout << "\n\nPress any key to continue..."; getch(); MainMenu(); }
        else if (c == '3') deleteOperation();
        else if (c == '4') searchTweetInNode();
        else if (c == '5') { countNodes(); cout << "\nPress any key..."; getch(); MainMenu(); }
        else if (c == '6') { thanksLine(); exit(0); }
        return 0;
    }

    void thanksLine()
    {
        cout << "\n\nThank you for using Tweet Manager!\n\n";
    }
};


   // ============================================================
   //  SECTION 3 : MAIN FUNCTION � Program Entry Point
   // ============================================================

   /*
     -> @brief Application Entry Point
     -> Architeture : Hybrid Model (Singly + Doubly Linked List)
     ->Designed for : Dezyne �cole College 1st Year 2nd Semester Project
   */
int main()
{
    system("cls");
    system("color 0F");//Bright White text on Black Background for better readability
    cout << "============================================\n";
    cout << "       TWEET MANAGER - BCA PROJECT       \n";
    cout << "     Singly & Doubly Linked List in C++    \n";
    cout << "============================================\n\n";
    cout << "Which data structure do you want to use?\n\n";
    cout << "1. Singly Linked List  (LinkList.cpp)\n";
    cout << "2. Doubly Linked List  (doublyll.cpp)\n";
    cout << "3. Exit\n\n";
    cout << "Choose -- ";

    //Interaction Logic : getch() is used for instant menu response whithout 'Enter'
    char ch = getch();

    if (ch == '1')
    {
        LinkList singly;
        singly.MainMenu();
    }
    else if (ch == '2')
    {
        DLinkList doubly;
        doubly.MainMenu();
    }
    else if (ch == '3')
    {
        cout << "\n\nThank you for using Tweet Manager!\n\n";
        return 0;
    }

    cout << "\n\nThank you for using Tweet Manager!\n\n";
    return 0;
}

/*
 ============================================================
  HOW TO COMPILE AND RUN (on Windows with Dev-C++ or MinGW)
  ------------------------------------------------------------
  1. Open TweetManager.cpp in Dev-C++ or any C++ IDE
  2. Press F11 to Compile & Run
     OR use command line:
       g++ TweetManager.cpp -o TweetManager.exe
       TweetManager.exe

  NOTE: <conio.h> is Windows-only (used for getch()).
        This program is designed for Windows/Dev-C++.
 ============================================================
*/



