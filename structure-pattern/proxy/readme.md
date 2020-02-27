Nếu Decorator để mở rộng các chức năng của 1 đối tượng, thì Proxy cũng có 1 chức năng tương tự nhưng mục tiêu của nó là bảo toàn độ chính xác của API đang được sử dụng
Nói cách khác Proxy không cố gắng mở rộng các chức năng hiện có của 1 lớp mà nó sẽ tăng cường các chức năng của đối tượng đó


Proxy không phải là 1 API đồng nhất bởi vì các loại proxy khác nhau với nhiều mục địch khác nhau 

Dưới đây là 1 vài loại proxy khá thông dụng:

- Smart pointer: là loại proxy đơn giản nhất và minh hoạ trực tiếp nhất về proxy. Là 1 wrapper cho 1 đối tượng mà nó sẽ tham chiếu các biến cũng như ghi đè các toàn thử của đối tượng đó. Và hơn hết nó sẽ cung cấp cho bạn tất cả nhưng interface mà đối tượng đó có. Sự khác biệt giữa smart pointer và pointer đó là sẽ không phải gọi xoá smart pointer.

- Property Proxy: trong các ngôn ngữ thì nó sẽ được thể hiện bởi get/set. Các đối tượng độc lập có thể thay thế và thực thi các operation khác mỗi khi assign hoặc truy cập vào property của nó

- Virtual proxy: Cung cấp quyền truy cập ảo vào đối tựơng, và thực hiện các hành vi như loading. Bạn sẽ cảm thấy như đang làm việc với 1 object thật sự mặc dù nó chưa hề được khởi tạo.

- Communication proxy : Cho phép chúng ta thay đổi vị trí vật lý của đối tượng (chuyển lên cloud...) nhưng vẫn sử dụng được cùng 1 API.

- Logging proxy: cho phép bạn thực hiện log khi gọi đến 1 function