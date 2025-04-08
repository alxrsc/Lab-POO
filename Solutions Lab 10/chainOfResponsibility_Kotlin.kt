// sursa de informare (same with c++): https://www.geeksforgeeks.org/chain-of-responsibility-method-design-patterns-in-c/

// pros:
// - permite unui obiect sa trateze o cerere fara a fi nevoie sa stie detalii despre cerere
// - permite mai multor obiecte sa trateze cererea
// - permite clientului sa trateze obiectele individuale si compuse uniform

// cons:
// - poate duce la o serie de update-uri in cascada
// - poate fi prea complex in cazuri relativ simple


// Base Handler Interface
interface AuthenticationHandler {
    fun setNextHandler(handler: AuthenticationHandler)
    fun handleRequest(request: String)
}

// Concrete Handler: Username and Password
class UsernamePasswordHandler : AuthenticationHandler {
    private var nextHandler: AuthenticationHandler? = null

    override fun setNextHandler(handler: AuthenticationHandler) {
        nextHandler = handler
    }

    override fun handleRequest(request: String) {
        if (request == "username-password") {
            println("Username and password authentication successful.")
        } else {
            nextHandler?.handleRequest(request) ?: println("Invalid authentication method.")
        }
    }
}

// Concrete Handler: Two-Factor Authentication
class TwoFactorHandler : AuthenticationHandler {
    private var nextHandler: AuthenticationHandler? = null

    override fun setNextHandler(handler: AuthenticationHandler) {
        nextHandler = handler
    }

    override fun handleRequest(request: String) {
        if (request == "two-factor") {
            println("Two-factor authentication successful.")
        } else {
            nextHandler?.handleRequest(request) ?: println("Invalid authentication method.")
        }
    }
}

// Concrete Handler: Text Message Authentication
class TextMessageHandler : AuthenticationHandler {
    private var nextHandler: AuthenticationHandler? = null

    override fun setNextHandler(handler: AuthenticationHandler) {
        nextHandler = handler
    }

    override fun handleRequest(request: String) {
        if (request == "text-message") {
            println("Text message authentication successful.")
        } else {
            nextHandler?.handleRequest(request) ?: println("Invalid authentication method.")
        }
    }
}

// Main function to demonstrate Chain of Responsibility
fun main() {
    val usernamePasswordHandler = UsernamePasswordHandler()
    val twoFactorHandler = TwoFactorHandler()
    val textMessageHandler = TextMessageHandler()

    // Set up the chain of responsibility
    usernamePasswordHandler.setNextHandler(twoFactorHandler)
    twoFactorHandler.setNextHandler(textMessageHandler)

    // Test the chain with various requests
    usernamePasswordHandler.handleRequest("username-password")
    usernamePasswordHandler.handleRequest("two-factor")
    usernamePasswordHandler.handleRequest("text-message")
    usernamePasswordHandler.handleRequest("invalid")
}
