use std::io;

fn get_string() -> io::Result<String> {
    let mut buffer = String::new();

    io::stdin().read_line(&mut buffer)?;

    Ok(buffer)
}

fn main() {
    let buffer = match get_string() {
        Ok(buffer) => buffer,
        Err(_) => "error".to_string(),
    };
    print!("{}", buffer);
}
