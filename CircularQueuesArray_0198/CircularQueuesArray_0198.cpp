#include <iostream>
using namespace std;

class Queues {
    int FRONT, REAR, max = 5;
    int queue_array[5];

public:
    Queues() {
        FRONT = -1;
        REAR = -1;
    }

    void insert() 
    {
        int num;
        cout << "Enter a number: ";
        cin >> num;
        cout << endl;

        //cek apakah antrian penuh
        if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR - 1))
        {
            cout << "Queue is overflow\n";
            return;
        }

        //cek apakah antrian kosong
        if (FRONT == -1)
        {
            FRONT = 0;
            REAR = 0;
        }
        else
        {
            if (REAR == max - 1)
                REAR = 0;
            else
                REAR = REAR + 1;
        }
        queue_array[REAR] = num;
    }

    void remove()
    {
        //cek apakah antrian kosong
        if (FRONT == -1)
        {
            cout << "Queue is underflow\n";
            return;
        }
        cout << "\nThe element deleted from the queue is: \n" << queue_array[FRONT] << "\n";

        //cek apakah antrian hanya memlikii satu elemen
        if (FRONT == REAR)
        {
            FRONT = -1;
            REAR = -1;
        }
        else
        {
            //jika elemen yang dihapus di posisi terakhir array, kembali ke awal array
            if (FRONT == max - 1)
                FRONT = 0;
            else
                FRONT = FRONT + 1;
        }
    }

    void display()
    {
        int FRONT_Position = FRONT;
        int REAR_Position = REAR;

        //cek apakah antrian kosong
        if (FRONT_Position == -1)
        {
            cout << "Queue is empty\n";
            return;
        }

        cout << "\nElements in the queue are...\n";

        //jika front <= rear, iterasi dari front hingga rear
        if (FRONT_Position <= REAR_Position)
        {
            while (FRONT_Position <= REAR_Position)
            {
                cout << queue_array[FRONT_Position] << "  " <<
                    FRONT_Position++;
            }
            cout << endl;
        }
        else
        {
            //jika front > rear, iterasi dari front hingga akhir array
            while (FRONT_Position <= max - 1)
            {
                cout << queue_array[FRONT_Position] << "  " << FRONT_Position++;
            }

            FRONT_Position = 0;

            //iterasi dari awal array hinga rear
            while (FRONT_Position <= REAR_Position)
            {
                cout << queue_array[FRONT_Position] << "  " <<
                    FRONT_Position++;
            }
            cout << endl;
        }
    }
};

