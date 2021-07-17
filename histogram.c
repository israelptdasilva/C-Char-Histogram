#include <stdio.h>
#include <stdlib.h>

/// This program prints a histogram of the frenquency of characters typed in the program's input.
/// There are no limit of characters that can be typed. 

/// A structure to model a linked list.
typedef struct _node {
  int code;
  int count;
  struct _node *next;
} Node;

/// A struct that holds head and tail nodes.
typedef struct _queue {
  Node *head;
  Node *tail;
  int count;
} Queue;

/// Initializes a new queue.
/// - Parameter queue: The queue to be initialized.
void initializeQueue(Queue *queue) {
  queue->head = NULL;
  queue->tail = NULL;
  queue->count = 0;
}

/// Adds a new node to a queue.
/// - Parameter queue: A queue that will hold the new node.
/// - Parameter code: The new node's code.
void enqueue(Queue *queue, int code) {
  Node *node = (Node *) malloc(sizeof(Node));
  node->code = code;
  node->count = 1;

  if (queue->head == NULL) {
    queue->tail = node;
    node->next = NULL;
  } else
    node->next = queue->head;

  queue->head = node;
  queue->count++;
}

/// Remove nodes from a queue on a FIFO basis. The caller is responsible for freeing the dequeued node.
/// - Parameter queue: A queue holding a linked list of nodes.
/// - Returns Node: The called is responsible for freeing the dequeued node.
void dequeue(Queue *queue) {
  Node *copy = queue->head;
  if (queue->head == queue->tail) {
    queue->head = queue->tail = NULL; 
    free(copy);
  } else {
    while (copy->next != queue->tail) {
      copy = copy->next;
    }
    queue->tail = copy;
    copy = copy->next;
    queue->tail->next = NULL;
    free(copy);
  }
  queue->count--;
} 

/// Gets a node based on a node code.
/// - Parameter *head: The current head node in which the desired node is contained.
/// - Parameter code: The data that matches that of the desired node.
/// - Returns: The desired node based on the provided code.
Node *get(Node *head, int code) {
  while (head != NULL) {
    if (head->code == code) {
      return head;
    }
    head = head->next;
  }
  return NULL;
}

/// Bubble sorts a Queue of nodes based on node code: order is higher to lower.
/// - Parameter queue: A queue of nodes that have a code.
void sort(Queue *queue) {
  Node *head = queue->head;
  Node *next = NULL;

  while (head != NULL) {
    next = head->next;
    while(next != NULL) {
      if (next->count > head->count) {
        int code = head->code;
        int count = head->count;
        head->code = next->code;
        head->count = next->count;
        next->code = code;
        next->count = count;
      }
      next = next->next;
    }
    head = head->next;
  }
}

/// Prints a horizontal histogram of the codes contained in a queue of nodes.
/// - Parameter queue: A queue that holds one or more nodes.
void hhistogram(Queue *queue) {
  Node *node = queue->head;
  while(node != NULL) {
    printf("%c ", node->code);
    for (int j = 0; j < node->count; j++)
      putchar('-');
    printf(" %d \n", node->count);
    node = node->next;
  }
}

/// Prints a vertical histogram of the numbers contained in an array.
/// - Parameter list: An array of integers.
/// - Parameter maxsize: The max size of the array. 
void vhistogram(Queue *queue) {
  Node *node = queue->head;
  
  if (node == NULL) 
    return;

  for (int i = 0; i < queue->count; i++) {
    printf("%c|", node->code);
    node = node->next;
  }

  for (int y = queue->head->count; y >= 0; y--) {
    node = queue->head;
    
    for (int x = 0; x < queue->count; x++) {
      if (node->count > y) {
        putchar('*');
        putchar(' ');
      }
     
      node = node->next;
    }
    
    putchar('\n');
  }
}

void main() {
  int c = 0;
  Queue queue;
  initializeQueue(&queue);

  while(c = getchar()) {
    if (c == '\n' || c == EOF)
      break;
    if (c == '\t' || c == ' ')
      continue;

    Node *node = get(queue.head, c);
    if (node == NULL) 
      enqueue(&queue, c);
    else
      node->count++;
  }

  sort(&queue);
  printf("\n");
  hhistogram(&queue);
  printf("\n");
  vhistogram(&queue);
  
  while (queue.head != NULL)
   dequeue(&queue);
}
