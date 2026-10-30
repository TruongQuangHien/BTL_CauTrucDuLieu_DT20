# BTL_CauTrucDuLieu_DT20
BaiTapLon_Nhom8
Hệ thống Quản lý Nhân sự & Bảng lương Cơ quan

Chương trình console viết bằng C++ dùng để quản lý hồ sơ nhân sự và tính bảng lương hằng tháng cho cơ quan. Dự án là bài tập lớn môn Cấu trúc dữ liệu và giải thuật, trong đó các cấu trúc dữ liệu (cây nhị phân tìm kiếm, danh sách liên kết, ngăn xếp) được tự cài đặt và áp dụng vào một bài toán thực tế.

Giới thiệu chung

Chương trình cho phép người dùng thực hiện qua menu dòng lệnh:

Quản lý hồ sơ nhân viên: thêm, tìm, sửa, xóa.
Tính lương thực lĩnh dựa trên hệ số lương, ngày công, giờ làm thêm (OT), phụ cấp và số ngày đi trễ.
Thống kê lương, xếp loại KPI theo ngày công.
Theo dõi lịch sử thay đổi lương và hoàn tác thao tác xóa nhầm.
Tự động lưu và nạp dữ liệu từ file văn bản, nên dữ liệu không mất khi thoát chương trình.
Chức năng
STT	Chức năng	Mô tả
1	Thêm nhân viên	Nhập đầy đủ thông tin, mã nhân viên không được trùng
2	Tìm theo mã NV	Tìm kiếm nhanh trên cây BST
3	Tìm theo mức lương tối thiểu	Liệt kê nhân viên có lương thực lĩnh từ mức nhập vào trở lên, kết quả tăng dần theo lương
4	Xóa nhân viên	Xử lý đủ 3 trường hợp xóa node (lá, một con, hai con)
5	Cập nhật thông tin	Sửa thông tin, chấm công, OT, đi trễ; tự ghi lịch sử nếu lương thay đổi
6	In danh sách	Xuất toàn bộ nhân viên tăng dần theo mã (duyệt LNR)
7	Thống kê lương	Lương trung bình, cao nhất, thấp nhất
8	Lịch sử thay đổi lương	Xem lương cũ và lương mới (mới nhất hiển thị trước)
9	Xếp loại KPI	Sắp xếp theo ngày công giảm dần và xếp loại A/B/C/D
10	Tổng quỹ lương tháng	Tổng lương phải trả và tổng tiền đã trừ do đi trễ
11	Hoàn tác xóa	Khôi phục nhân viên bị xóa gần nhất
12	Lưu dữ liệu ngay	Ghi dữ liệu xuống file
0	Lưu và thoát	Lưu dữ liệu, giải phóng bộ nhớ rồi thoát
Cấu trúc dữ liệu sử dụng
Cấu trúc	Vai trò trong chương trình
BST chính (khóa là maNV)	Lưu hồ sơ nhân viên; thêm, tìm, xóa theo mã; duyệt LNR để in danh sách có thứ tự
BST phụ (khóa là cặp lương, maNV)	Tìm nhân viên theo mức lương nhanh, không cần duyệt toàn bộ cây chính. Luôn được đồng bộ với BST chính khi thêm, xóa, sửa
Danh sách liên kết đơn	Lưu lịch sử thay đổi lương (LichSuLuong), thêm vào đầu danh sách
Ngăn xếp (Stack)	Lưu các nhân viên đã xóa để hoàn tác theo nguyên tắc vào sau ra trước (LIFO)
Mảng động	Dùng tạm khi xếp loại KPI (thu thập từ cây rồi sắp xếp theo ngày công)
Quy tắc tính lương
Lương theo hệ số = Hệ số lương × Lương cơ bản
Lương ngày công  = Lương theo hệ số × Số ngày công / 26
Lương OT         = (Lương theo hệ số / 26 / 8) × 1.5 × Số giờ OT
Tiền trừ đi trễ  = Số ngày đi trễ × 50.000 VND

Lương thực lĩnh  = Lương ngày công + Phụ cấp + Lương OT − Tiền trừ đi trễ

Các hằng số quy ước trong code:

Số ngày công chuẩn của tháng: 26 ngày, mỗi ngày 8 giờ.
Hệ số OT: 1.5 (HE_SO_OT).
Mức trừ mỗi ngày đi trễ: 50.000 VND (TIEN_TRU_MOT_NGAY_TRE).
Lương thực lĩnh không bao giờ âm (nếu kết quả âm thì lấy bằng 0).
Xếp loại KPI theo ngày công
Loại	Điều kiện
A	Từ 26 ngày công trở lên
B	Từ 22 đến 25 ngày công
C	Từ 16 đến 21 ngày công
D	Dưới 16 ngày công
Thông tin lưu cho mỗi nhân viên

Mã nhân viên, họ tên, chức vụ, phòng ban, hệ số lương, phụ cấp, số ngày công, số giờ OT, lương cơ bản và số ngày đi trễ.

Lưu trữ dữ liệu

Dữ liệu được lưu trong file nhanvien.txt cùng thư mục với chương trình. Mỗi nhân viên là một dòng, các trường cách nhau bằng dấu |:

maNV|hoTen|chucVu|phongBan|heSo|phuCap|ngayCong|gioOT|luongCoBan|ngayTre

Ví dụ:

NV001|Nguyen Van A|Truong phong|Ke toan|3.00|500000|26|4.00|5000000|1

Lưu ý:

Chương trình tự nạp file khi khởi động và tự lưu sau mỗi thao tác thêm, xóa, sửa, hoàn tác, cũng như khi thoát.
Có thể đọc file định dạng cũ (8 trường, không có chức vụ và số ngày đi trễ).
Dữ liệu ghi theo thứ tự NLR để khi nạp lại, cây BST giữ nguyên hình dạng.
Ký tự | trong dữ liệu nhập vào sẽ được tự đổi thành - để không làm hỏng file.
Hướng dẫn cài đặt và biên dịch
1. Yêu cầu hệ thống
Hệ điều hành: Windows, Linux hoặc macOS.
Trình biên dịch hỗ trợ C++11 trở lên (chương trình dùng stod, stoi). Khuyến nghị g++ 7.0 trở lên.
Chương trình chỉ dùng thư viện chuẩn của C++, không cần cài thêm thư viện ngoài.
2. Cài đặt trình biên dịch

Windows

Cách 1: cài MinGW-w64 hoặc MSYS2, sau đó thêm thư mục bin của MinGW vào biến môi trường PATH.
Cách 2: cài một IDE đã kèm sẵn trình biên dịch như Dev-C++ hoặc Code::Blocks (bản có MinGW).
Cách 3: cài Visual Studio (chọn workload Desktop development with C++).

Linux (Ubuntu/Debian)

bash
sudo apt update
sudo apt install build-essential

macOS

bash
xcode-select --install
3. Tải mã nguồn

Đặt file BTLCAUTRUC.cpp vào một thư mục riêng, ví dụ QuanLyNhanSu/. Nếu dự án nằm trên Git:

bash
git clone <đường-dẫn-repository>
cd <tên-thư-mục-dự-án>
4. Kiểm tra trình biên dịch
bash
g++ --version

Nếu lệnh in ra thông tin phiên bản thì môi trường đã sẵn sàng.

5. Biên dịch

Bằng g++ (Windows, Linux, macOS)

bash
g++ -std=c++11 -Wall -O2 BTLCAUTRUC__2_.cpp -o quanlynhansu

Bằng Visual Studio (Developer Command Prompt)

bat
cl /EHsc /std:c++14 BTLCAUTRUC__2_.cpp /Fe:quanlynhansu.exe

Bằng IDE (Dev-C++ / Code::Blocks)

Mở file BTLCAUTRUC.cpp.
Vào cài đặt trình biên dịch và đảm bảo đã bật chuẩn C++11 (Dev-C++: Tools → Compiler Options → Settings → Code Generation → Language standard = ISO C++11).
Nhấn F11 (Dev-C++) hoặc F9 (Code::Blocks) để biên dịch và chạy.
6. Chạy chương trình
bash
# Linux / macOS
./quanlynhansu

# Windows (CMD hoặc PowerShell)
quanlynhansu.exe

Khi khởi động, chương trình tự nạp dữ liệu từ nhanvien.txt nếu file này tồn tại. Nếu chưa có, file sẽ được tạo tự động ở lần lưu đầu tiên.

7. Lưu ý khi sử dụng
Hãy chạy chương trình ngay trong thư mục chứa file thực thi để nhanvien.txt được đọc và ghi đúng chỗ.
Luôn thoát bằng chức năng 0. Lưu và thoát để dữ liệu được lưu đầy đủ.
Có thể sao lưu dữ liệu bằng cách sao chép file nhanvien.txt.
Giao diện không dùng ký tự có dấu nên hiển thị tốt trên mọi terminal, không cần cấu hình bảng mã.
8. Xử lý lỗi thường gặp
Lỗi	Nguyên nhân và cách khắc phục
'g++' is not recognized...	Chưa cài g++ hoặc chưa thêm vào PATH. Cài MinGW và thêm thư mục bin vào PATH
'stod' was not declared in this scope	Chưa bật chuẩn C++11. Thêm tùy chọn -std=c++11 khi biên dịch
Khong mo duoc file de ghi!	Thư mục đang chạy không có quyền ghi. Chạy chương trình ở thư mục khác hoặc cấp quyền ghi
Dữ liệu không còn sau khi mở lại	Đang chạy ở thư mục khác nên đọc nhầm nhanvien.txt. Chạy lại đúng thư mục chứa file dữ liệu
Giới hạn dữ liệu nhập
Trường	Khoảng hợp lệ
Hệ số lương	0.1 – 100
Phụ cấp	0 – 100.000.000
Số ngày công	0 – 31
Số giờ OT	0 – 200
Lương cơ bản	1 – 1.000.000.000
Số ngày đi trễ	0 – số ngày công

Nhập sai định dạng hoặc ngoài khoảng cho phép, chương trình sẽ yêu cầu nhập lại.

Độ phức tạp
Thêm, tìm, xóa theo mã: O(h), với h là chiều cao cây (trung bình O(log n), xấu nhất O(n) vì cây không tự cân bằng).
Tìm theo mức lương: O(h + k), với k là số kết quả tìm được.
In danh sách (LNR), thống kê: O(n).
Xếp loại KPI: O(n²) do dùng sắp xếp đổi chỗ đơn giản.
