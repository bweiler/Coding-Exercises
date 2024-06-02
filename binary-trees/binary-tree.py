class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.val = key


class BinaryTree:
    def __init__(self):
        self.root = None

    def insert(self, root, key):
        if root is None:
            self.root = Node(key)
        else:
            if root.val < key:
                if root.right is None:
                    root.right = Node(key)
                else:
                    self.insert(root.right, key)
            else:
                if root.left is None:
                    root.left = Node(key)
                else:
                    self.insert(root.left, key)

    def inorder_traversal(self, root):
        if root:
            self.inorder_traversal(root.left)
            print(root.val, end=" ")
            self.inorder_traversal(root.right)

    def preorder_traversal(self, root):
        if root:
            print(root.val, end=" ")
            self.preorder_traversal(root.left)
            self.preorder_traversal(root.right)

    def postorder_traversal(self, root):
        if root:
            self.postorder_traversal(root.left)
            self.postorder_traversal(root.right)
            print(root.val, end=" ")


# Example usage:
if __name__ == "__main__":
    tree = BinaryTree()
    tree.insert(tree.root, 50)
    tree.insert(tree.root, 30)
    tree.insert(tree.root, 20)
    tree.insert(tree.root, 40)
    tree.insert(tree.root, 70)
    tree.insert(tree.root, 60)
    tree.insert(tree.root, 80)

    print("Inorder traversal:")
    tree.inorder_traversal(tree.root)
    print("\nPreorder traversal:")
    tree.preorder_traversal(tree.root)
    print("\nPostorder traversal:")
    tree.postorder_traversal(tree.root)

# Output:
# Inorder traversal: 20 30 40 50 60 70 80
# Preorder traversal: 50 30 20 40 70 60 80
# Postorder traversal: 20 40 30 60 80 70 50
