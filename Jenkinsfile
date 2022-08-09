pipeline {
    agent none
    stages {
        stage('Check norme') {
        agent {docker 'epitechcontent/epitest-docker:latest'}
        steps {
            sh 'echo "hello world"'
            }
        }
    }
}
