# Traveling salesman problem (TSP)
## Bài toán
Bài toán trả lời cho câu hỏi:

Cho trước danh sách các thành phố và các con đường nối giữa các thành phố ấy. Ta cần tìm ra tuyến đường ngắn nhất đi từ một thành phố, đi qua tất cả các thành phố khác (mỗi thành phố ghé qua đúng một lần) và quay lại thành phố xuất phát.

## Ý tưởng
Một cách giải đơn giản là sử dụng tư duy vét cạn. Tức là từ một đỉnh đã chọn, ta xét các đỉnh còn lại phải đi qua và tạo ra các bộ hoán vị của những đỉnh này.

Ví dụ: Xét một đồ thị có 4 cạnh lần lượt là **A**, **B**, **C**, **D**. Nếu ta bắt đầu từ đỉnh **A**, các đỉnh còn lại lần lượt là **B**, **C**, **D**. Giờ đây, ta xét lần lượt các hoán vị của chúng với đỉnh xuất phát. Như vậy các đường đi có thể xảy ra là:
- A -> B -> C -> D
- A -> B -> D -> C
- A -> C -> B -> D
- A -> C -> D -> B
- A -> D -> B -> C
- A -> D -> C -> B

Đương nhiên, sau đỉnh kết thúc ta cần quay lại đỉnh xuất phát. Như vậy, các đường đi có thể xảy ra đầy đủ là:
- A -> B -> C -> D -> A
- A -> B -> D -> C -> A
- A -> C -> B -> D -> A
- A -> C -> D -> B -> A
- A -> D -> B -> C -> A
- A -> D -> C -> B -> A

Với mỗi hoán vị, ta cần tính tổng chi phí của đường đi đó. Cuối cùng, ta chọn ra đường đi có chi phí nhỏ nhất. Một số đường đi trong danh sách hoán vị trên có thể sẽ không đúng. Giả sử ta không có cạnh nối 2 đỉnh A và C, như thế 2 đường đi sau sẽ không hợp lệ:
- A -> C -> B -> D -> A
- A -> C -> D -> B -> A

Dù thế, cách giải này có độ phức tạp rất lớn, vì số hoán vị của **n - 1** đỉnh (không xét đỉnh xuất phát) là **(n - 1)!**. Với đồ thị có số đỉnh **n** lớn, việc tính toán trở nên không khả thi hoặc mất rất nhiều thời gian.

## Cài đặt thuật toán
### Hàm tạo ra hoán vị kế tiếp
#### Mô tả
Như đã trình bày ở ý tưởng, việc đầu tiên cần thực hiện là viết một hàm tạo ra hoán vị kế tiếp của tập đỉnh hiện tại. Hàm này sẽ trả về **true** nếu còn hoán vị tiếp theo, ngược lại trả về **false**.

Nguyên mẫu hàm như sau:
```cpp
bool nextPermutation(int current[TSM_MAX_VERTICES], int n);
```

Trong đó:
- `current`: mảng chứa hoán vị hiện tại. Ở lần hoán vị đầu tiên, mảng này chứa các phần tử được sắp xếp có thứ tự tăng dần.
- `n`: số lượng phần tử của mảng.
- Hằng số `TSM_MAX_VERTICES`: số lượng đỉnh tối đa của đồ thị (trong bài này bằng `20`).

#### Cài đặt
```cpp
bool nextPermutation(int current[TSM_MAX_VERTICES], int n) {
    // (1)
	int i = n - 1;
	while (i > 0 && current[i - 1] >= current[i]) {
		i--;
	}
	if (i <= 0) {
		return false;
	}

	// (2)
	int j = n - 1;
	while (current[j] <= current[i - 1]) {
		j--;
	}

	// (3)
	int temp = current[i - 1];
	current[i - 1] = current[j];
	current[j] = temp;

	// (4)
	j = n - 1;
	while (i < j) {
		temp = current[i];
		current[i] = current[j];
		current[j] = temp;
		i++;
		j--;
	}

	return true;
}
```

#### Giải thích
Ở hàm trên, ta thực hiện các bước sau:
- Bước `(1)`: Tìm vị trí `i` sao cho `current[i - 1] < current[i]` (tức là tìm ra phần tử ở vị trí `i` lớn nhất sao cho phần tử này lớn hơn phần tử trước nó). Nếu không tìm được, tức là hoán vị hiện tại đã là hoán vị cuối cùng, ta trả về `false`. Điều này có nghĩa là không còn hoán vị nào khác nữa, xảy ra khi mảng `current` đã được sắp xếp giảm dần. Giả sử với mảng `current` là `[5, 4, 3, 2, 1]`, ta không thể tìm ra vị trí `i` nào thỏa mãn điều kiện `current[i - 1] < current[i]`. Nhưng với mảng `current` là `[1, 2, 3, 5, 4]`, ta có thể tìm ra vị trí `i = 3` thỏa mãn điều kiện trên.
- Bước `(2)`: Tìm vị trí `j` sao cho `current[j] > current[i - 1]` (tức là tìm ra phần tử ở vị trí `j` lớn nhất sao cho phần tử này lớn hơn phần tử ở vị trí `i - 1`). Ví dụ với mảng `current` là `[1, 2, 3, 5, 4]`, sau bước `(1)` ta có `i = 3`, sau bước `(2)` ta có `j = 4`.
- Bước `(3)`: Hoán đổi giá trị của `current[i - 1]` và `current[j]`. Ví dụ với mảng `current` là `[1, 2, 3, 5, 4]`, sau bước `(2)` ta có `current[i - 1] = 3` và `current[j] = 4`, sau bước này ta có mảng `current` là `[1, 2, 4, 5, 3]` (đổi chỗ 2 phần tử `3` và `4`)
- Bước `(4)`: Đảo ngược các phần tử từ vị trí `i` đến vị trí cuối cùng của mảng `current`. Điều này giúp ta tạo ra một hoán vị mới lớn hơn hoán vị hiện tại nhưng vẫn nhỏ hơn hoán vị kế tiếp. Ví dụ với mảng `current` là `[1, 2, 4, 5, 3]`, sau bước `(3)` ta có `i = 3`, sau bước `(4)` ta có mảng `current` là `[1, 2, 4, 3, 5]`. Đây chính là hoán vị kế tiếp của mảng `current` là `[1, 2, 3, 5, 4]` ở ban đầu.

### Hàm tính toán đường đi ngắn nhất
#### Mô tả
Trong hàm này, ta sẽ sinh ra tất cả các hoán vị của các đỉnh (trừ đỉnh xuất phát) và tính toán chi phí của từng hoán vị. Cuối cùng, ta chọn ra hoán vị có chi phí nhỏ nhất và trả ra đường đi ứng với hoán vị đó.

Nguyên mẫu hàm như sau:
```cpp
string Traveling(int graph[TSM_MAX_VERTICES][TSM_MAX_VERTICES], int numOfVertices, char startVertex);
```

Trong đó:
- `graph`: ma trận kề của đồ thị. `graph[i][j]` là chi phí đi từ đỉnh `i` đến đỉnh `j`. Nếu không có cạnh nối giữa 2 đỉnh `i` và `j` thì `graph[i][j] = 0`.
- `numOfVertices`: số lượng đỉnh của đồ thị.
- `startVertex`: đỉnh xuất phát.
- Hằng số `TSM_MAX_VERTICES`: số lượng đỉnh tối đa của đồ thị (trong bài này bằng `20`).

#### Cài đặt
```cpp
string Traveling(int graph[TSM_MAX_VERTICES][TSM_MAX_VERTICES], int numOfVertices, char startVertex) {
	int startVertexIndex = startVertex - 'A';

	// (1)
	int current[TSM_MAX_VERTICES];
	for (int i = 0, j = 0; i < numOfVertices; i++, j++) {
		if (i == startVertexIndex) {
			j--;
			continue;
		}
		current[j] = i;
	}

	// (2)
	int minCost = INT_MAX;
	string minPath;

	// (3)
	do {
		int cost = 0;
		int previous = startVertexIndex;

		// (3.1)
		for (int i = 0; i < numOfVertices - 1; i++) {
			if (graph[previous][current[i]] == 0) {
				cost = INT_MAX;
				break;
			}
			cost += graph[previous][current[i]];
			previous = current[i];
		}
		if (graph[previous][startVertexIndex] == 0 || cost == INT_MAX) {
			cost = INT_MAX;
		}
		else {
			cost += graph[previous][startVertexIndex];
		}

		// (3.2)
		if (cost < minCost) {
			minCost = cost;
			string t;
			t.push_back(startVertex);
			for (int i = 0; i < numOfVertices - 1; i++) {
				t.push_back(' ');
				t.push_back(current[i] + 'A');
			}
			t.push_back(' ');
			t.push_back(startVertex);
			minPath = t;
		}
	} while (nextPermutation(current, numOfVertices - 1));

    // (4)
	return minPath;
}
```

#### Giải thích
Ở hàm trên, ta thực hiện các bước sau:
- Bước `(1)`: Khởi tạo mảng `current` chứa các đỉnh cần hoán vị. Đỉnh xuất phát sẽ không được chứa trong mảng này. Ví dụ với số lượng đỉnh là `5` và đỉnh xuất phát là `C`, mảng `current` sẽ chứa các đỉnh `[0, 1, 3, 4]`.
- Bước `(2)`: Khởi tạo biến `minCost` là giá trị lớn nhất của kiểu `int` (`INT_MAX` - ở đây ta giả định nó đang mang một giá trị vô cùng lớn) và biến `minPath` là chuỗi rỗng.
- Bước `(3)`: Với mỗi hoán vị của mảng `current`, ta tính toán chi phí của đường đi tương ứng. Nếu đường đi không hợp lệ (tức là không có cạnh nối giữa 2 đỉnh liên tiếp hoặc không có cạnh nối giữa đỉnh cuối cùng và đỉnh xuất phát), ta gán chi phí bằng `INT_MAX`. Ngược lại, ta tính tổng chi phí của đường đi. Nếu chi phí này nhỏ hơn `minCost`, ta cập nhật `minCost` và `minPath`. Trong đó:
    - Bước `(3.1)`: Tính tổng chi phí của đường đi. Với mỗi đỉnh, ta kiểm tra xem có cạnh nối giữa đỉnh hiện tại và đỉnh tiếp theo không. Nếu không có, ta gán chi phí bằng `INT_MAX`.
    - Bước `(3.2)`: Nếu chi phí của đường đi nhỏ hơn `minCost`, ta cập nhật `minCost` và `minPath`.
- Bước `(4)`: Trả về đường đi ngắn nhất.

## Kết luận
Trên đây là cách giải bài toán TSP bằng phương pháp vét cạn. Tuy nhiên như đã đề cập, cách giải này có độ phức tạp rất lớn, vì số hoán vị với đồ thị có số đỉnh **n** sẽ là rất lớn nếu **n** lớn, việc tính toán trở nên không khả thi hoặc mất rất nhiều thời gian. Để giải quyết vấn đề này, ta cần sử dụng các phương pháp tối ưu hơn.

## Các tài liệu tham khảo
1. [Traveling salesman problem - Wikipedia](https://en.wikipedia.org/wiki/Travelling_salesman_problem)
2. [Traveling Salesman Problem - GeeksforGeeks](https://www.geeksforgeeks.org/traveling-salesman-problem-tsp-implementation/)
3. [std::next_permutation() in C++ - Techiedelight](https://www.techiedelight.com/std_next_permutation-overview-implementation/)


<p align="center">---Hết---</p>
