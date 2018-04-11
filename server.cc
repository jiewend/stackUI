#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<iostream>
#include <sys/types.h> 
#include <sys/time.h> 
#include "app_datapackage.h" 
// #include "unp.h" 
#define PICTURE_BUFF_SIZE 1024
#define MAX_CONNECTION 5
#define SERVER_PORT 9080

void recvPicture(int socket);
bool recvPictureInStruct(int clnt_sock);
void sendPicture(int clnt_sock);
void sendBack(int clnt_sock);
void sendBackImagePackage(int clnt_sock);

int main()
{
    using namespace std;
	// cout<<"sizeof App_DataPackage : "<<sizeof(App_DataPackage)<<endl;
	// cout<<"sizeof PictureHeader : "<<sizeof(PictureHeader)<<endl;
	cout<<"sizeof PicturePackage : "<<sizeof(PicturePackage)<<endl;
    int serv_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    char endFlag[] = {"end"};
    int endFlagSize = sizeof (endFlag);
    struct sockaddr_in serv_addr;

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(SERVER_PORT);


    cout<<"SERVER_PORT = "<<SERVER_PORT<<endl;
    bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    listen(serv_sock, 1);
    struct sockaddr_in clnt_addr;
    socklen_t clnt_addr_size = sizeof(clnt_addr);

	fd_set fdsr;
	int socket_list[MAX_CONNECTION];
	bzero(socket_list, sizeof(socket_list));
	struct timeval tv;
	int ret;
	int current_connection = 0;
	char recvBuff[sizeof(PicturePackage)];
	int maxfd = 0;
	while(1){
		FD_ZERO(&fdsr);
		FD_SET(serv_sock, &fdsr);
		FD_SET(0, &fdsr);
		tv.tv_sec = 5;
		tv.tv_usec = 0;
		maxfd = max(serv_sock, socket_list[0]);

		for(int i = 0; i<MAX_CONNECTION; i++){
			if(socket_list[i] != 0){
				cout<<"add socket No."<<i<<endl;
				FD_SET(socket_list[i], &fdsr);
			}
		}
		ret = select(maxfd + 1, &fdsr, NULL, NULL, &tv);
		if(ret < 0){
			perror("select");
			break;
		} else if(ret == 0){
			cout<<"timeout"<<endl;
			continue;
		}
		//检查已有连接上是否有数据可读
		for(int i = 0; i < current_connection; i++){
				cout<<"checking socket No."<<i<<endl;
				if(FD_ISSET(socket_list[i], &fdsr)){
					// sendBack(socket_list[i]);
					sendBackImagePackage(socket_list[i]);
/*
					if(recvPictureInStruct(socket_list[i])){
						close(socket_list[i]);
						FD_CLR(socket_list[i], &fdsr);
						socket_list[i] = 0;
					}
*/					
	   /*              ret = recv(socket_list[i], recvBuff, sizeof(PicturePackage), 0); */
					   // if(ret <= 0){
						// cout<<"clent No."<<i<<" close"<<endl;
						// close(socket_list[i]);
						// FD_CLR(socket_list[i]);
						// socket_list[i] = 0;
					// } else {
						// cout<<recvBuff<<endl;
					/* } */
			}
				//检查标准输入是否有数据
				if(FD_ISSET(0, &fdsr)){
					sendPicture(socket_list[0]);
				}
		}
		
		//检查是否有新客户端连接
		if(FD_ISSET(serv_sock, &fdsr)){
			socket_list[current_connection++] = 
				accept(serv_sock, (struct sockaddr*)&clnt_addr, &clnt_addr_size);
			cout<<"new clent connected!"<<"current_connection : "<<current_connection<<endl;
		}


	}
    char str[1024] ;//= "Hello World!";
    struct App_DataPackage recvPackage;

    int clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_addr, &clnt_addr_size);
    if (clnt_sock == 0) { 
       cout<<"client connect failed"<<endl; 
    } 
    cout<<"client connected success!"<<endl;

	// recvPicture(clnt_sock);
	recvPictureInStruct(clnt_sock);




   /*  char buff[PICTURE_BUFF_SIZE]; */
	// bzero(buff, sizeof(buff));
	// int length = 0;
	// FILE *fd = fopen("picture", "w");
	// if(fd == NULL){
		// cout<<"open file fail"<<endl;
	// }else{
		// while(length = recv(clnt_sock, buff, PICTURE_BUFF_SIZE, 0)){
			// int write_length = fwrite(buff, sizeof(char), length, fd);
			// if(write_length < length){
				// cout<<"file write fail"<<endl;
				// break;
			// }
			// bzero(buff, sizeof(buff));

		// }
	// }
	// fclose(fd);
	// while(1){
	
	// }



   /*  while(1){ */
		// char inputData[PACKAGE_SIZE];
		// char sendBuff[sizeof(App_DataPackage)];
		// bzero(inputData, sizeof(inputData));
		// bzero(sendBuff, sizeof(sendBuff));
		// cin>>inputData;
		// memcpy(recvPackage.data_buffer, inputData, sizeof(PACKAGE_SIZE));
		// recvPackage.SourceID = 3;
		// recvPackage.DestinationID = 1;
		// recvPackage.Package_type = 4;
		// recvPackage.data_size = PACKAGE_SIZE;
		// recvPackage.SerialNum = 64;
		// memcpy(sendBuff, &recvPackage, sizeof(App_DataPackage));
		// for (unsigned i = 0; i < 3; ++i) { 
			// write(clnt_sock, &sendBuff, sizeof(App_DataPackage));
		// } 

	
	/* } */

/*     while(1){ */
		// bzero(&recvPackage, sizeof(recvPackage));
        // if(read(clnt_sock, &str, sizeof(recvPackage))){
			// memcpy(&recvPackage,str, sizeof(recvPackage));

			// int sourceId = recvPackage.SourceID;
			// int destinId = recvPackage.DestinationID;
			// int packgeType = recvPackage.Package_type;
			// int dataSize = recvPackage.data_size;
            // cout<<"data_buffer = "<<recvPackage.data_buffer<<endl;
			// if (memcmp(recvPackage.data_buffer, endFlag, endFlagSize) == 0) { 
				// break;
			// }
			// else{
				// uint8_t temp = recvPackage.DestinationID;
				// recvPackage.DestinationID = recvPackage.SourceID;
				// recvPackage.SourceID = temp;
				// recvPackage.Package_type = 3;
				// bzero(recvPackage.data_buffer, sizeof(PACKAGE_SIZE));
				// for (unsigned i = 0; i <7 ; ++i) { 
					// recvPackage.data_buffer[i] = i; 
				// } 
				// recvPackage.data_buffer[7] = 127;
				// bzero(str, sizeof(str));
				// memcpy(str, &recvPackage, sizeof(recvPackage));
				// write(clnt_sock, &str, sizeof(recvPackage));
		// }
	// }
/* } */
   /*  int inputDest = 2, inputSour = 1, firstData = 0, wait; */
	// while(1){
		// cin>>inputDest;
		// cin>>inputSour;
		// cin>>firstData;
		// // cin>>wait;
		// // firstData++;
		// cout<<"inputDest : "<<inputDest<<"  inputSour : "<<inputSour<<"  firstData : "<<firstData<<endl;
		// if((firstData > 4)[>  || (firstData < 1) <]){
			// cout<<"invalue input !"<<endl;
			// // break;
		// }
		// else{
			// bzero(&recvPackage, sizeof(recvPackage));
			// recvPackage.data_size = sizeof(recvPackage);
			// recvPackage.Package_type = 6;
			// recvPackage.DestinationID = inputDest; //inputDest;
			// recvPackage.SourceID = inputSour;//inputSour;
			// recvPackage.data_buffer[0] = firstData;
			// cout<<"data_buffer[0] = "<<recvPackage.data_buffer[0]<<endl;
			// recvPackage.SerialNum = 100;
			// bzero(str, sizeof(str));
			// memcpy(str, &recvPackage, sizeof(recvPackage));
			// write(clnt_sock, &str, sizeof(recvPackage));
		// }
	/* } */

    close(serv_sock);
    cout<<"connect finsish"<<endl;
    return 0;
}



void sendBack(int clnt_sock){
	char temp[sizeof(PicturePackage)];
	bzero(temp, sizeof(temp));
	while(read(clnt_sock, temp, sizeof(PicturePackage))){
		write(clnt_sock, temp, sizeof(PicturePackage));
		bzero(temp, sizeof(temp));
	}
}
void sendBackImagePackage(int clnt_sock){
	using namespace std;
	char temp[sizeof(ImageHeader)];
	ImageHeader tempImage;
	bzero(temp, sizeof(temp));
	while(int readlen = read(clnt_sock, temp, sizeof(ImageHeader))){
		if(readlen < sizeof(ImageHeader)){
			read(clnt_sock, temp + readlen, sizeof(ImageHeader) - readlen);
		}
		memcpy(&tempImage, temp, sizeof(ImageHeader));
		cout<<"readlen : "<<readlen<<" type : "<<(int)tempImage.Package_type<<"destId : "<<(int)tempImage.DestinationID<<endl;
		int* rgb = (int*)tempImage.data_buffer;
		// for (unsigned i = 0; i < PICTURE_BUFF_SIZE / sizeof(int); ++i) { 
			// cout<<"pix : "<<*(rgb + i) <<endl;
		// } 
		write(clnt_sock, temp, sizeof(temp));
		bzero(temp, sizeof(temp));
		bzero(&tempImage, sizeof(tempImage));
	}
}
void sendPicture(int clnt_sock){
	using namespace std;
	int a;
	cin>>a;
	cout<<"begin to send picture"<<endl;
	struct PicturePackage sendStructBuff;
	char readFileBuff[PICTUER_PACKAGE_SIZE], sendBuff[sizeof(PicturePackage)];
	bzero(readFileBuff, sizeof(readFileBuff));
	bzero(&sendStructBuff, sizeof(sendStructBuff));
	FILE *fd = fopen("/home/ucc/forSend", "r");
	int saveReadFileLength = 0;
	time_t now;
	time(&now);
	uint8_t usePictureID = now % 255;
	int fileReadLength = 0;
	int writeLength = 0;
	int i = 0;
	if(fd == NULL){
		cout<<"open file fail"<<endl;
	} else {
		while(fileReadLength = fread(readFileBuff, sizeof(char), PICTUER_PACKAGE_SIZE , fd)){
			cout<<"read "<<fileReadLength<<"byte"<<endl;
			sendStructBuff.data_size = fileReadLength;
			sendStructBuff.pictureID = usePictureID;
			sendStructBuff.Package_type = 5;
			sendStructBuff.serialNum = i++;
			memcpy(sendStructBuff.data_buffer, readFileBuff, fileReadLength);
			cout<<"data_size : "<<sendStructBuff.data_size<<"at No."<<i<<endl;
			cout<<"serialNum : "<<(int)sendStructBuff.serialNum<<endl;
			memcpy(sendBuff, &sendStructBuff, sizeof(sendStructBuff));
			if(i != 255){
				writeLength = write(clnt_sock, sendBuff, sizeof(sendBuff));
				cout<<"send "<<writeLength<<" byte"<<i<<endl;
				bzero(readFileBuff, sizeof(readFileBuff));
				bzero(&sendStructBuff, sizeof(sendStructBuff));
				if(saveReadFileLength > fileReadLength){
					cout<<"send file finish"<<endl;
					return;
				}else{
					saveReadFileLength = fileReadLength;
				}
			} else{ 
				sendBuff[555] = 'u';
				i++;
				writeLength = write(clnt_sock, sendBuff, sizeof(sendBuff));
			}
		}
	}
}
void recvPicture(int clnt_sock){
	using namespace std;
	char buff[PICTURE_BUFF_SIZE];
	bzero(buff, sizeof(buff));
	int length = 0;
	FILE *fd = fopen("picture", "w");
	if(fd == NULL){
		cout<<"open file fail"<<endl;
	}else{
		while(length = recv(clnt_sock, buff, PICTUER_PACKAGE_SIZE, 0)){
			int write_length = fwrite(buff, sizeof(char), length, fd);
			if(write_length < length){
				cout<<"file write fail"<<endl;
				break;
			}
			bzero(buff, sizeof(buff));

		}
	}
	fclose(fd);
}

bool recvPictureInStruct(int clnt_sock){
	using namespace std;
	cout<<"begin to recv picture"<<endl;
	char buff[sizeof(PicturePackage)];
	bzero(buff, sizeof(buff));
	int length = 0;
	int i = 0;
	FILE *fd = fopen("pictureInStruct", "w");
	struct PicturePackage recvStruct;
	bzero(&recvStruct, sizeof(recvStruct));
	int saveData_Size = 0;
	if(fd == NULL){
		cout<<"open file fail"<<endl;
	}else{
		while(length = read(clnt_sock, buff, sizeof(PicturePackage))){
			
			if(length < 0){
				cout<<"connect finish"<<endl;
				fclose(fd);
				return true;
			}
			cout<<"recv "<<length<<" byte"<<"at No."<<i++<<endl;
			// memcpy(&recvStruct, buff, sizeof(PicturePackage));
			memcpy(&recvStruct, buff, length);
			cout<<"data_size : "<<recvStruct.data_size<<endl;
			int write_length = fwrite(recvStruct.data_buffer,sizeof(char), recvStruct.data_size, fd);
			if(recvStruct.data_size < saveData_Size){
				return false;
			} else {
				saveData_Size = recvStruct.data_size;
			}
			bzero(&recvStruct, sizeof(recvStruct));
			bzero(buff, sizeof(buff));
			if(write_length < recvStruct.data_size){
				cout<<"file write fail"<<endl;
				return false;	
			}
		}
	}
	
	// int a;
	// cin>>a;
	cout<<"file recv finish"<<endl;
	fclose(fd);
	return true;
}
