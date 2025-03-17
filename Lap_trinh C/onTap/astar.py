import heapq

class Node:
    def __init__(self, position, g_cost=float('inf'), h_cost=0):
        self.position = position  # Vị trí node (x, y)
        self.g_cost = g_cost    # Chi phí từ điểm bắt đầu đến node hiện tại
        self.h_cost = h_cost    # Chi phí ước tính từ node hiện tại đến đích
        self.f_cost = g_cost + h_cost  # Tổng chi phí
        self.parent = None      # Node cha

def heuristic(node, goal):
    # Tính khoảng cách Manhattan
    return abs(node[0] - goal[0]) + abs(node[1] - goal[1])

def get_neighbors(node, grid):
    neighbors = []
    directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]  # 4 hướng di chuyển
    
    for dx, dy in directions:
        new_x = node[0] + dx
        new_y = node[1] + dy
        
        # Kiểm tra xem vị trí mới có hợp lệ không
        if (0 <= new_x < len(grid) and 
            0 <= new_y < len(grid[0]) and 
            grid[new_x][new_y] != 1):  # 1 đại diện cho chướng ngại vật
            neighbors.append((new_x, new_y))
    
    return neighbors

def a_star(start, goal, grid):
    # Khởi tạo node bắt đầu
    start_node = Node(start, 0, heuristic(start, goal))
    
    # Danh sách mở và đóng
    open_list = []
    closed_set = set()
    
    # Thêm node bắt đầu vào danh sách mở
    heapq.heappush(open_list, (start_node.f_cost, id(start_node), start_node))
    
    while open_list:
        # Lấy node có f_cost thấp nhất
        current_node = heapq.heappop(open_list)[2]
        
        # Kiểm tra xem đã đến đích chưa
        if current_node.position == goal:
            path = []
            while current_node:
                path.append(current_node.position)
                current_node = current_node.parent
            return path[::-1]
        
        # Thêm vào danh sách đóng
        closed_set.add(current_node.position)
        
        # Kiểm tra các node lân cận
        for neighbor_pos in get_neighbors(current_node.position, grid):
            if neighbor_pos in closed_set:
                continue
                
            # Tính chi phí mới
            new_g_cost = current_node.g_cost + 1
            
            neighbor_node = Node(
                neighbor_pos,
                new_g_cost,
                heuristic(neighbor_pos, goal)
            )
            neighbor_node.parent = current_node
            
            # Thêm vào danh sách mở
            heapq.heappush(open_list, 
                          (neighbor_node.f_cost, id(neighbor_node), neighbor_node))
    
    return None  # Không tìm thấy đường đi

# Ví dụ sử dụng
if __name__ == "__main__":
    # 0: đường đi trống
    # 1: chướng ngại vật
    grid = [
        [0, 0, 0, 0, 1],
        [1, 1, 0, 1, 0],
        [0, 0, 0, 0, 0],
        [0, 1, 1, 1, 0],
        [0, 0, 0, 1, 0]
    ]
    
    start = (0, 0)  # Điểm bắt đầu
    goal = (4, 4)   # Điểm đích
    
    path = a_star(start, goal, grid)
    
    if path:
        print("Tìm thấy đường đi:", path)
        
        # In ra lưới với đường đi
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if (i, j) == start:
                    print("S", end=" ")
                elif (i, j) == goal:
                    print("G", end=" ")
                elif (i, j) in path:
                    print("*", end=" ")
                else:
                    print(grid[i][j], end=" ")
            print()
    else:
        print("Không tìm thấy đường đi!") 