#include<stdio.h> 
#include<stdlib.h> 
#include<string>
#include<time.h> 
#include<vector>
#include<iostream>
using namespace std ; 
struct event{ 
    int oid = -1; 
    int arival = -1; 
    int duration = -1; 
    int timeout = -1; 
    int departure; 
    int abort; 
    int delay; 
    int count = 0; 
}; 
class JobQueue{ 
    vector<event> queue; 
    int qFront, qBack; 
    int qSize, qMax; 
    int next(int index){ 
        return(index + 1) % qMax; 
    } 
    int pre(int index){ 
        return(index + qMax - 1) % qMax; 
    } 
    public : 
    void mission1(string fileName){ 
        event work; 
        event temp; 
        int i = 0 ,k = 0,m = 0; 
        int j = 0; 
        int h = 1; 
        clock_t start, end; 
        double read, sort, write; 
        char c; 
        vector<event> waitlist; 
        FILE *infile = NULL; 
        FILE *outfile = NULL; 
        infile = fopen(("input"+fileName+".txt").c_str(),"r"); 
        start = clock(); 
        if ( infile == NULL) 
            cout << fileName << "does not exist!"<< endl; 
            else{ 
                while(c != '\n'){ 
                    fscanf(infile, "%c", &c) ; 
                } 
                waitlist.push_back(work) ; 
                while(fscanf(infile, "%d", &waitlist[i].oid) != -1){ 
                    fscanf(infile, "%d %d %d", &waitlist[i].arival, &waitlist[i].duration, &waitlist[i].timeout); 
                    waitlist.push_back(work) ; i++ ; 
                } 
                k = i-1; 
                m = k; 
                end = clock() ; 
                read = ((double)(end - start)); 
                waitlist.pop_back(); 
                h = waitlist.size() / 2 + 1; 
                while (h >= 1) { 
                    for ( i = h; i < waitlist.size(); i++) { 
                        j = i ; 
                        while (j >= h) { 
                            if(waitlist[j].arival >= waitlist[j - h].arival){ 
                                if(waitlist[j].arival > waitlist[j - h].arival){ 
                                    temp = waitlist[j] ; waitlist[j] = waitlist[j - h] ; 
                                    waitlist[j - h] = temp ; 
                                } 
                                else if(waitlist[j].arival = waitlist[j - h].arival){ 
                                    if(waitlist[j].oid > waitlist[j - h].oid){ 
                                        temp = waitlist[j] ; waitlist[j] = waitlist[j - h] ; waitlist[j - h] = temp ; 
                                    } 
                                    else{ 
                                        break ; 
                                    } 
                                } 
                            } 
                            else{ 
                                break ; 
                            } 
                            j = j - h ; 
                        } 
                    } 
                    if( h % 2 != 0 && h != 1){ 
                        h = h / 2 + 1 ; 
                    } 
                    else{ 
                        h = h / 2 ; 
                    } 
                } 
                while ( k >= 0){ 
                    if (waitlist[k].oid == -1 || waitlist[k].arival == -1 || waitlist[k].duration == -1 || waitlist[k].timeout == -1 ) { 
                        cout << "Data error!"<< endl; return ; 
                    } 
                    k--; 
                } 
                for ( m = m ; m > 0 ; m-- ) { 
                    for ( k = m-1; k >= 0 ; k--) { 
                        if (waitlist[m].oid == waitlist[k].oid ) { 
                            cout << "have the same oid!" << endl; 
                            return ; 
                        } 
                    } 
                } 
                outfile = fopen(("sorted" + fileName + ".txt").c_str(),"a"); 
                end = clock() ; 
                sort = ((double)(end - start)) ; 
                i-- ; 
                fprintf(outfile, "OID\tArival\tDuration\tTimeout\n") ; 
                while(i >= 0){ 
                    fprintf(outfile, "%d\t%d\t%d\t%d\n", waitlist[i].oid, waitlist[i].arival, waitlist[i].duration, waitlist[i].timeout) ; 
                    i-- ; 
                } 
                end = clock() ; 
                write = ((double)(end - start)) ; 
                printf("Reading data : %fms\n", read) ; 
                printf("Sorting data : %fms\n", sort) ; 
                printf("Wrinting data : %fms\n", write) ; 
                fclose(outfile); 
                return ; 
            } 
        } 
        void mission2( string fileName){ 
            int i = 0 ,k = 0, m =0; 
            int j = 0 ,d = 0; 
            event work ; 
            event temp ; 
            float averdelay = 0 ; 
            float finishper = 0 ; 
            float a ; 
            float b ; 
            vector<event> waitlist ; 
            vector<event> cancellist ; 
            vector<event> finishlist ; 
            vector<event> schedule ; 
            int count = 1 ; 
            FILE *infile = NULL; 
            FILE *outfile = NULL; 
            infile = fopen(("sorted"+fileName+".txt").c_str(),"r"); 
            char c ; 
            if (infile == NULL) 
                cout << fileName << "does not exist!"<< endl; 
            else{ 
                while(c != '\n'){ 
                    fscanf(infile, "%c", &c) ; 
                } 
                waitlist.push_back(work) ; 
                while(fscanf(infile, "%d", &waitlist[0].oid) != -1){ 
                    fscanf(infile, "%d %d %d", &waitlist[0].arival, &waitlist[0].duration, &waitlist[0].timeout); 
                    waitlist.insert(waitlist.begin(), work); 
                } 
                waitlist.erase(waitlist.begin()) ; 
                k = waitlist.size() - 1 ; 
                m = k; 
                while (k >= 0){ 
                    if (waitlist[k].oid == -1 || waitlist[k].arival == -1 || waitlist[k].duration == -1 || waitlist[k].timeout == -1 ) { 
                        cout << "Data error!"<< endl; return ; 
                    } 
                    k--; 
                } 
                for ( m = m ; m > 0 ; m-- ) { 
                    for ( k = m-1; k >= 0 ; k--) { 
                        if (waitlist[m].oid == waitlist[k].oid ) { 
                            cout << "have the same oid!" << endl; 
                            return ; 
                        } 
                    } 
                } 
                while(!waitlist.empty() || !schedule.empty()){ 
                    while(!schedule.empty() && (schedule[schedule.size() - 1].timeout <= count || schedule[schedule.size() - 1].count == schedule[schedule.size() - 1].duration)){ 
                        if(schedule[schedule.size() - 1].count == schedule[schedule.size() - 1].duration){ 
                            schedule[schedule.size() - 1].departure = count ; 
                            schedule[schedule.size() - 1].delay = count - schedule[schedule.size() - 1].arival - schedule[schedule.size() - 1].duration ; 
                            finishlist.push_back(schedule[schedule.size() - 1]) ; 
                            schedule.pop_back() ; 
                            i-- ; 
                        } 
                        else if(schedule[schedule.size() - 1].timeout <= count){ 
                            schedule[schedule.size() - 1].abort = count ; 
                            schedule[schedule.size() - 1].delay = count - schedule[schedule.size() - 1].arival ; 
                            cancellist.push_back(schedule[schedule.size() - 1]) ; 
                            schedule.pop_back() ; 
                            i-- ; 
                        } 
                    } 
                    while(!waitlist.empty() && waitlist[waitlist.size() - 1].arival == count){ 
                        if(i < 4){ 
                            schedule.insert(schedule.begin(), waitlist[waitlist.size() - 1]) ; 
                            waitlist.pop_back() ; 
                            i++ ; 
                        } 
                        else{ 
                            waitlist[waitlist.size() - 1].abort = waitlist[waitlist.size() - 1].arival ; 
                            waitlist[waitlist.size() - 1].delay = 0 ; 
                            cancellist.push_back(waitlist[waitlist.size() - 1]) ; 
                            waitlist.pop_back() ; 
                        } 
                    } 
                    if(!schedule.empty()){ 
                        schedule[schedule.size() - 1].count++ ; 
                    } 
                    count++ ; 
                } 
                for(i = 0 ; i < cancellist.size() || i < finishlist.size() ; i++){ 
                    if(i < cancellist.size()){ 
                        averdelay = averdelay + cancellist[i].delay ; 
                    } 
                    if(i < finishlist.size()){ 
                        averdelay = averdelay + finishlist[i].delay ; 
                    } 
                } 
                averdelay = averdelay / (cancellist.size() + finishlist.size()) ; 
                a = finishlist.size() ; 
                b = cancellist.size() + finishlist.size() ; 
                finishper = 100 * a / b ; 
                outfile = fopen(("output" + fileName + ".txt").c_str(),"a"); 
                fprintf(outfile, " \t[Abort Jobs]\n") ; 
                fprintf(outfile, " \tOID\tAbort\tDelay\n") ; 
                for(i = 0 ; i < cancellist.size() ; i++){ 
                    fprintf(outfile, "[%d]\t%d\t%d\t%d\n", i + 1, cancellist[i].oid, cancellist[i].abort, cancellist[i].delay) ; 
                } 
                fprintf(outfile, " \t[Jobs Done]\n") ; fprintf(outfile, " \tOID\tDeparture\tDelay\n") ; 
                for(i = 0 ; i < finishlist.size() ; i++){ 
                    fprintf(outfile, "[%d]\t%d\t%d\t%d\n", i + 1, finishlist[i].oid, finishlist[i].departure, finishlist[i].delay) ; 
                } 
                fprintf(outfile, "[Average Delay]\t%fms\n", averdelay) ; 
                fprintf(outfile, "[Success Rate]\t%f", finishper) ; 
                fprintf(outfile, "%c", 37) ; 
                fclose(outfile); 
            } 
        } 
}; 
int main(){ 
    JobQueue k ; 
    int method = 0, test = 0; 
    string name; 
    vector<event> temp; 
    while ( test == 0) { 
        cout << "Input a command(0，1，2):"; 
        cin >> method; 
        if ( method == 0 ) break; 
        if ( method != 0 && method != 1 && method != 2) { 
            cout << "Please try again!"; 
            break ; 
        } 
        cout << "Input a file number:"; 
        cin >> name; 
        if( method == 1) {
            k.mission1(name); 
        } 
        if( method == 2) { 
            k.mission2(name) ; 
        } 
        cout << "input 0 to retry:"; 
        cin >> test; 
    }
}