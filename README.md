# BaiTapOOPNhom21
Võ Lâm Truyền Kỳ

# Bài tập OOP nhóm 21
## Võ Lâm Truyền Kỳ

## Đề bài
Xây dựng chương trình mô phỏng game võ lâm truyền kì với các mô tả như sau: 
Võ lâm truyền kì là một tựa game theo phong cách nhập vai kiếm hiệp xuất hiện từ những ngày đầu trên thị trường game online Việt Nam. Trong game, người chơi có thể tương tác với nhau để giải trí hoặc tiêu diệt quái vật để phát triển nhân vật của mình. 
Nhân vật: Được xem như đại diện cho một người chơi. Mỗi nhân vật thuộc về một môn phái nào đó trong tổng số 10 môn phái của game. Một nhân vật có một giá trị thể hiện cấp độ và mức sát thương. Trong đó Sát thương = Cấp độ x 5

 Quái vật: Để gia tăng cấp độ nhân vật của mình, mỗi người chơi sẽ thông qua việc tiêu diệt các quái vật. Có hai loại quái vật: thông thường và đầu lĩnh. Các quái vật cũng sẽ có khả năng tấn công lại người chơi. Quái vật thông thường: Sát thương = Cấp độ x 3. Quái vật đầu lĩnh: Sát thương = Cấp độ x 7 
Một nét đặc sắc của game đó là hệ thống ngũ hành tương sinh tương khắc, mỗi một môn phái và quái vật sẽ thuộc về một “hành” nhất định và tương tác giữa các người chơi với nhau, giữa người chơi với quái vật đều dựa trên các quy tắc về ngũ hành.

Hệ Kim: 

 o Thiếu Lâm 
 
 o Thiên Vương bang 

Hệ Mộc: 

 o Ngũ Độc giáo 
 
 o Đường Môn 

Hệ Thủy: 

 o Nga My 
 
 o Thúy Yên môn 

Hệ Hỏa: 

 o Cái Bang 
 
 o Thiên Nhẫn giáo 

Hệ Thổ: 

 o Côn Lôn 
 
 o Võ Đang 

![alt text](https://github.com/realhaidinh/BaiTapOOPNhom21/blob/main/nguhanh.png?raw=true)

Quy tắc tương sinh: (S) Sát thương gây ra cho người chơi hoặc quái vật + 10 % 
Ví dụ: Hoả sinh thổ, sát thương người chơi (hoặc quái vật) hệ hoả gây ra cho người chơi (hoặc quái vật) hệ thổ + 10 % 
Quy tắc tương khắc: (K) Sát thương gây ra cho người chơi hoặc quái vật ± 20 % 
Ví dụ: Mộc khắc thổ, sát thương người chơi (hoặc quái vật) hệ mộc gây ra cho người chơi (hoặc quái vật) hệ thổ + 20 %. Ngược lại, sát thương người chơi (hoặc quái vật) hệ thổ gây ra cho người chơi (hoặc quái vật) hệ mộc - 20 %

Áp dụng kiến thức lập trình hướng đối tượng (kế thừa, đa hình) thiết kế sơ đồ chi tiết các lớp đối tượng và xây dựng chương trình thực hiện các yêu cầu sau: 
1. Tạo và quản lý một danh sách các người chơi và quái vật.  
2. Cho biết phần tử có mức sát thương cao nhất trong danh sách. 
3. Cho hai phần tử A và B, so sánh giá trị sát thương tác động A lên B và ngược lại. 

##Cài đặt

Build project bằng Visual Studio 2022
