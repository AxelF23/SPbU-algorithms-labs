#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <cmath>

using namespace std;


const int k = 5;
const double a1 = 0.7, a2 = 1.3;
const double b1 = 1.0, b2 = 2.5;
const double c1 = 0.8, c2 = 3.0;

enum EventType { ARRIVAL, FINISH1, FINISH2 };


struct Event {
    double time;
    EventType type;
    Event* next;
};


struct Request {
    int id;
    double arrival_time;
    double service_time;
    double start_time;
    int queue_id;
};


struct RequestNode {
    Request data;
    RequestNode* next;
};


struct RequestQueue {
    RequestNode* front;
    RequestNode* rear;
    int size;
};


struct EventQueue {
    Event* front;
};


struct QueueStats {
    int entered = 0;
    int exited = 0;
    double total_wait = 0;
    double max_wait = 0;


struct ServerStats {
    int processed = 0;
    double busy_time = 0;
};


double current_time = 0.0;
int total_processed = 0;
int next_id = 1;


QueueStats queue1_stats, queue2_stats;
ServerStats server1_stats, server2_stats;


RequestQueue queue1 = {nullptr, nullptr, 0};
RequestQueue queue2 = {nullptr, nullptr, 0};


Request* server1 = nullptr;
Request* server2 = nullptr;


EventQueue event_queue = {nullptr};


double rand_uniform(double min, double max) {
    return min + (max - min) * (rand() / (double)RAND_MAX);
}


void push_event(EventQueue* eq, double time, EventType type) {
    Event* new_event = new Event;
    new_event->time = time;
    new_event->type = type;
    new_event->next = nullptr;

    if (eq->front == nullptr) {
        eq->front = new_event;
    } else {

        Event* current = eq->front;
        Event* prev = nullptr;

        while (current && current->time < time) {
            prev = current;
            current = current->next;
        }

        if (prev == nullptr) {
            new_event->next = eq->front;
            eq->front = new_event;
        } else {
            prev->next = new_event;
            new_event->next = current;
        }
    }
}


Event pop_event(EventQueue* eq) {
    if (eq->front == nullptr) {
        return {0, ARRIVAL, nullptr};
    }

    Event* front_event = eq->front;
    Event result = *front_event;

    eq->front = front_event->next;
    delete front_event;

    return result;
}


bool is_event_queue_empty(EventQueue* eq) {
    return eq->front == nullptr;
}


void push_request(RequestQueue* rq, Request req) {
    RequestNode* new_node = new RequestNode;
    new_node->data = req;
    new_node->next = nullptr;

    if (rq->rear == nullptr) {
        rq->front = rq->rear = new_node;
    } else {
        rq->rear->next = new_node;
        rq->rear = new_node;
    }

    rq->size++;
}


Request pop_request(RequestQueue* rq) {
    if (rq->front == nullptr) {
        return {};
    }

    RequestNode* front_node = rq->front;
    Request result = front_node->data;

    rq->front = front_node->next;
    if (rq->front == nullptr) {
        rq->rear = nullptr;
    }

    delete front_node;
    rq->size--;

    return result;
}


bool is_request_queue_empty(RequestQueue* rq) {
    return rq->front == nullptr;
}


int request_queue_size(RequestQueue* rq) {
    return rq->size;
}


void generate_package() {
    double interval = rand_uniform(a1, a2);
    double arrival_time = current_time + interval;

    for (int i = 0; i < k; i++) {
        Request req;
        req.id = next_id++;
        req.arrival_time = arrival_time;
        req.queue_id = (rand() % 2) + 1;


        if (req.queue_id == 1) {
            req.service_time = rand_uniform(b1, b2);
            push_request(&queue1, req);
            queue1_stats.entered++;
        } else {
            req.service_time = rand_uniform(c1, c2);
            push_request(&queue2, req);
            queue2_stats.entered++;
        }
    }
}


void process_arrival() {

    generate_package();

    double next_arrival_time = current_time + rand_uniform(a1, a2);
    push_event(&event_queue, next_arrival_time, ARRIVAL);
}


void start_service(int server_id) {
    Request req;
    RequestQueue* rq = (server_id == 1) ? &queue1 : &queue2;

    if (!is_request_queue_empty(rq)) {

        req = pop_request(rq);


        if (server_id == 1) {
            queue1_stats.exited++;
            server1 = new Request(req);
        } else {
            queue2_stats.exited++;
            server2 = new Request(req);
        }


        req.start_time = current_time;


        double finish_time = current_time + req.service_time;
        EventType finish_type = (server_id == 1) ? FINISH1 : FINISH2;
        push_event(&event_queue, finish_time, finish_type);
    }
}


void finish_service(int server_id) {
    Request* req = (server_id == 1) ? server1 : server2;

    if (req) {

        double wait_time = req->start_time - req->arrival_time;


        if (server_id == 1) {
            queue1_stats.total_wait += wait_time;
            if (wait_time > queue1_stats.max_wait) {
                queue1_stats.max_wait = wait_time;
            }
            server1_stats.processed++;
            server1_stats.busy_time += req->service_time;
            delete server1;
            server1 = nullptr;
        } else {
            queue2_stats.total_wait += wait_time;
            if (wait_time > queue2_stats.max_wait) {
                queue2_stats.max_wait = wait_time;
            }
            server2_stats.processed++;
            server2_stats.busy_time += req->service_time;
            delete server2;
            server2 = nullptr;
        }


        total_processed++;
    }
}


void print_intermediate_stats() {
    cout << "\n=== Промежуточная статистика (" << total_processed << " обработано) ===" << endl;


    double avg_wait1 = queue1_stats.exited > 0 ?
                      queue1_stats.total_wait / queue1_stats.exited : 0.0;
    cout << "Очередь 1: длина=" << request_queue_size(&queue1)
         << ", макс.ожидание=" << fixed << setprecision(2) << queue1_stats.max_wait
         << ", среднее=" << avg_wait1 << endl;


    double avg_wait2 = queue2_stats.exited > 0 ?
                      queue2_stats.total_wait / queue2_stats.exited : 0.0;
    cout << "Очередь 2: длина=" << request_queue_size(&queue2)
         << ", макс.ожидание=" << queue2_stats.max_wait
         << ", среднее=" << avg_wait2 << endl;


    cout << "ОА1 обработано: " << server1_stats.processed << endl;
    cout << "ОА2 обработано: " << server2_stats.processed << endl;
    cout << "======================================" << endl;
}


void print_final_stats() {
    cout << "\n=== Финальная статистика ===" << endl;
    cout << "Общее время моделирования: " << fixed << setprecision(2) << current_time << endl;


    double idle_time1 = current_time - server1_stats.busy_time;
    cout << "ОА1: простой=" << idle_time1
         << ", обработано=" << server1_stats.processed << endl;


    double idle_time2 = current_time - server2_stats.busy_time;
    cout << "ОА2: простой=" << idle_time2
         << ", обработано=" << server2_stats.processed << endl;


    cout << "Очередь 1: вошло=" << queue1_stats.entered
         << ", вышло=" << queue1_stats.exited << endl;


    cout << "Очередь 2: вошло=" << queue2_stats.entered
         << ", вышло=" << queue2_stats.exited << endl;


    double avg_wait1 = queue1_stats.exited > 0 ?
                      queue1_stats.total_wait / queue1_stats.exited : 0.0;
    double avg_wait2 = queue2_stats.exited > 0 ?
                      queue2_stats.total_wait / queue2_stats.exited : 0.0;

    cout << "Среднее время ожидания (очередь 1): " << avg_wait1 << endl;
    cout << "Среднее время ожидания (очередь 2): " << avg_wait2 << endl;
    cout << "======================================" << endl;
}


void free_request_queue(RequestQueue* rq) {
    while (!is_request_queue_empty(rq)) {
        pop_request(rq);
    }
}


void free_event_queue(EventQueue* eq) {
    while (!is_event_queue_empty(eq)) {
        pop_event(eq);
    }
}


void simulate() {

    srand(time(nullptr));


    push_event(&event_queue, 0.0, ARRIVAL);

    while (total_processed < 1000 && !is_event_queue_empty(&event_queue)) {

        Event event = pop_event(&event_queue);


        current_time = event.time;


        switch (event.type) {
            case ARRIVAL:
                process_arrival();
                break;
            case FINISH1:
                finish_service(1);
                break;
            case FINISH2:
                finish_service(2);
                break;
        }


        if (!server1 && !is_request_queue_empty(&queue1)) {
            start_service(1);
        }
        if (!server2 && !is_request_queue_empty(&queue2)) {
            start_service(2);
        }


        if (total_processed % 100 == 0 && total_processed > 0) {
            print_intermediate_stats();
        }
    }


    print_final_stats();


    free_request_queue(&queue1);
    free_request_queue(&queue2);
    free_event_queue(&event_queue);
    if (server1) delete server1;
    if (server2) delete server2;
}

int main() {

    setlocale(LC_ALL, "Russian");


    simulate();

    return 0;
}
