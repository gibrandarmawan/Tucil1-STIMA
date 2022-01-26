#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<chrono>
using namespace std::chrono;
using namespace std;
vector<string>question;
vector<string>answer;



int main(){

    int total;
    fstream file_input;
    file_input.open("../test/large3.txt", ios::in);
  

    if (!file_input){
        cout << "File kosong";
    }
    else{
        
        bool flag = false;
        string line;

        while (getline(file_input, line)){
            if (line == ""){
                flag = true;
            }
                
            if (flag == false){
                line.erase(remove(line.begin(), line.end(), ' '), line.end());
                question.push_back(line);
            }
            else if(flag == true){
                answer.push_back(line);
            }

        }
        
        auto start = high_resolution_clock::now();
        for (int ya = 0; ya < answer.size(); ya++){
            for (int yq = 0; yq < question.size(); yq++){
                for (int xq = 0; xq < question[0].size() ; xq++){
                    if (question[yq][xq] == answer[ya][0]){
                        vector<string> result;
                        string resultString;
                        bool flag = true;
                        string jawaban;
                        int cnt = 0;

                        
                        for (int i = 0; i < question[0].size() ; i++){
                            resultString.push_back('_');
                        }

                         for(int j =0; j < question.size() ; j ++){
                            result.push_back(resultString);
                        }
                        
                        while (flag){
                            total++;
                            if (yq+cnt == question.size()){
                                break;
                            }
                            if (question[yq+cnt][xq] == answer[ya][cnt]){
                                jawaban += question[yq+cnt][xq];
                                result[yq+cnt][xq] = question[yq+cnt][xq];
                                cnt++;
                                
                                if (jawaban == answer[ya]){
                                    flag = false;
                                    for (auto i = result.begin(); i != result.end(); ++i){
                                            cout << *i << "\n";}
                                    cout << "\n";
                                      
                                }
                            }
                            else{
                                flag = false;
                            }
                        }

                        flag = true;
                        while (flag){  
                            total++;
                            if (yq+cnt == question.size()){
                                break;
                            }
                            if (question[yq+cnt][xq+cnt] == answer[ya][cnt]){
                                jawaban += question[yq+cnt][xq+cnt];
                                result[yq+cnt][xq+cnt] = question[yq+cnt][xq+cnt];
                                total++;
                                cnt++;
                                
                                if (jawaban == answer[ya]){
                                    flag = false;
                                    for (auto i = result.begin(); i != result.end(); ++i){
                                            cout << *i << "\n";}
                                    cout << "\n";
                                }
                            }
                            else{
                                flag = false;
                            }
                        }

                        flag = true;
                        while (flag){  
                            total++;
                            if (yq+cnt == question.size()){
                                break;
                            }
                            if (question[yq+cnt][xq-cnt] == answer[ya][cnt]){
                                jawaban += question[yq+cnt][xq-cnt];
                                result[yq+cnt][xq-cnt] = question[yq+cnt][xq-cnt];
                                cnt++;
                                
                                if (jawaban == answer[ya]){
                                    flag = false;
                                    for (auto i = result.begin(); i != result.end(); ++i){
                                            cout << *i << "\n";}
                                            cout << "\n";
                                }
                            }
                            else{
                                flag = false;
                            }
                        }

                        flag =true;            
                        while (flag){
                            total++;
                            if (question[yq][xq+cnt] == answer[ya][cnt]){
                                jawaban += question[yq][xq+cnt];
                                result[yq][xq+cnt] = question[yq][xq+cnt];
                                cnt++;
                                if (jawaban == answer[ya]){
                                    flag = false;
                                    for (auto i = result.begin(); i != result.end(); ++i){
                                            cout << *i << "\n";}
                                        cout << "\n";
                                }
                            }
                            else{
                                flag = false;
                            }
                        }

                        flag = true;
                        while (flag){
                            total++;
                            if (question[yq][xq-cnt] == answer[ya][cnt]){
                                result[yq][xq-cnt] = question[yq][xq-cnt];
                                jawaban += question[yq][xq-cnt];
                                cnt++;
                                if (jawaban == answer[ya]){
                                    flag = false;
                                    for (auto i = result.begin(); i != result.end(); ++i){
                                            cout << *i << "\n";}
                                    cout << "\n";
                                }
                            }
                            else{
                                flag = false;
                            }
                        }

                        jawaban = "";
                        resultString =  "";
                        result.clear();
                        for (int i = 0; i < (question[0].size()) ; i++){
                            resultString.push_back('_');
                        }
                         for(int j =0; j < question.size() ; j ++){
                            result.push_back(resultString);
                        }
                        
                        for(int x = 0 ; x <= yq ; x++){
                            total++;
                            if (question[yq-x][xq] == answer[ya][x]){
                                jawaban += question[yq-x][xq];
                                result[yq-x][xq] = question[yq-x][xq];
                                if (jawaban == answer[ya]){
                                    for (auto i = result.begin(); i != result.end(); ++i){
                                            cout << *i << "\n";}
                                    cout << "\n";
                                    break;
                                }
                            }
                            else{
                                break;
                            }
                        }
                        jawaban = "";
                        resultString =  "";
                        result.clear();
                        
                        for (int i = 0; i < question[0].size() ; i++){
                            resultString+="_";
                        }
                        
                        for(int j =0; j < question.size() ; j++){
                            result.push_back(resultString);
                        }
                        
                        for(int x = 0 ; x <= yq ; x++){
                            total++;
                            if (question[yq-x][xq+x] == answer[ya][x]){
                                jawaban += question[yq-x][xq+x];
                                result[yq-x][xq+x] = question[yq-x][xq+x];
                                if (jawaban == answer[ya]){
                                    for (auto i = result.begin(); i != result.end(); ++i){
                                        cout << *i << "\n";}
                                    cout << "\n";
                                    break;
                                }
                            }
                            else{
                                break;
                            }
                        }
                        jawaban = "";
                        resultString =  "";
                        result.clear();
                        for (int i = 0; i < question[0].size() ; i++){
                            resultString.push_back('_');
                        }

                         for(int j =0; j < question.size() ; j ++){
                            result.push_back(resultString);
                        }
                        for(int x = 0 ; x <= yq ; x++){
                            total++;
                            if (question[yq-x][xq-x] == answer[ya][x]){
                                jawaban += question[yq-x][xq+x];
                                result[yq-x][xq-x] = question[yq-x][xq-x];
                                if (jawaban == answer[ya]){
                                    for (auto i = result.begin(); i != result.end(); ++i){
                                            cout << *i << "\n";}
                                        cout << "\n";
                                    break;
                                }
                            }
                            else{
                                break;
                            }
                        }
                        
                    }
                }
               
            } 
        }
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);
        cout << "Durasi program: "
             << duration.count() << " milidetik \n" 
             << "Total perbandingan huruf: "
             << total << endl;
        
    }
    
    file_input.close();
    return 0;
}