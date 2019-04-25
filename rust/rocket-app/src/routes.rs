use rocket_contrib::json::Json;

use crate::models::ToDo;

#[get("/")]
pub fn index() -> &'static str{
    "hello, world!"
}

#[get("/todos")]
pub fn todos() -> Json<Vec<ToDo>> {
    Json(vec![ToDo {
        id: 1,
        title: "Read Rocket tutorial".into(),
        description: "Read https://rocket.rs/guide/quickstart/".into(),
        done:false,
    }])
}

#[post("/todos", data = "<todo>")]
pub fn new_todo(todo: Json<ToDo>) -> String {
    format!("Accept post request! {:?}", todo.0)
}



#[get("/todos/<todoid>")]
pub fn todo_by_id(todoid: u32) -> String {
    let todo = ToDo{
        id:1, 
        title: "Read Rocket tutorial".into(),
        description: "Read https://rocket.rs/guide/quickstart/".into(),
        done: false,
    };
    format!("{:?}", todo)
}
